#include "ExampleInterfaceWampProxy.hpp"

namespace example {

/*
std::shared_ptr<CommonAPI::DBus::DBusProxy> createExampleInterfaceDBusProxy(
	const CommonAPI::DBus::DBusAddress &_address,
	const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection) {
	return std::make_shared<ExampleInterfaceDBusProxy>(_address, _connection);
}

INITIALIZER(registerExampleInterfaceDBusProxy) {
	CommonAPI::DBus::Factory::get()->registerProxyCreateMethod(
		ExampleInterface::getInterface(),
		&createExampleInterfaceDBusProxy);
}
*/

ExampleInterfaceWampProxy::ExampleInterfaceWampProxy(
	const boost::asio::ip::tcp::endpoint &rawsocketEndpoint,
	const std::string &realm,
	bool debug) :
	m_rawsocketEndpoint(rawsocketEndpoint),
	m_realm(realm),
	m_debug(debug)
{
}


void ExampleInterfaceWampProxy::play(CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info) {
    try {
        boost::asio::io_service io;
        bool debug = parameters->debug();
        auto transport = std::make_shared<autobahn::wamp_tcp_transport>(
                io, m_rawsocketEndpoint, m_debug);

        auto session = std::make_shared<autobahn::wamp_session>(io, m_debug);

        transport->attach(std::static_pointer_cast<autobahn::wamp_transport_handler>(session));

        // Make sure the continuation futures we use do not run out of scope prematurely.
        // Since we are only using one thread here this can cause the io service to block
        // as a future generated by a continuation will block waiting for its promise to be
        // fulfilled when it goes out of scope. This would prevent the session from receiving
        // responses from the router.
        boost::future<void> connect_future;
        boost::future<void> start_future;
        boost::future<void> join_future;
        boost::future<void> call_future;
        boost::future<void> leave_future;
        boost::future<void> stop_future;

        connect_future = transport->connect().then([&](boost::future<void> connected) {
            try {
                connected.get();
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                io.stop();
                return;
            }
            std::cerr << "transport connected" << std::endl;

            start_future = session->start().then([&](boost::future<void> started) {
                try {
                    started.get();
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    io.stop();
                    return;
                }

                std::cerr << "session started" << std::endl;

                join_future = session->join(parameters->realm()).then([&](boost::future<uint64_t> joined) {
                    try {
                        std::cerr << "joined realm: " << joined.get() << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << e.what() << std::endl;
                        io.stop();
                        return;
                    }

                    autobahn::wamp_call_options call_options;
                    call_options.set_timeout(std::chrono::seconds(10));

                    std::tuple<> arguments;
                    call_future = session->call("com.examples.calculator.add2", arguments, call_options).then(
                    [&](boost::future<autobahn::wamp_call_result> result) {
                        try {
                            result.get();
                            std::cerr << "call successfull" << std::endl;
                        } catch (const std::exception& e) {
                            std::cerr << "call failed: " << e.what() << std::endl;
                            io.stop();
                            return;
                        }

                        leave_future = session->leave().then([&](boost::future<std::string> reason) {
                            try {
                                std::cerr << "left session (" << reason.get() << ")" << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "failed to leave session: " << e.what() << std::endl;
                                io.stop();
                                return;
                            }

                            stop_future = session->stop().then([&](boost::future<void> stopped) {
                                std::cerr << "stopped session" << std::endl;
                                io.stop();
                            });
                        });
                    });
                });
            });
        });

        std::cerr << "starting io service" << std::endl;
        io.run();
        std::cerr << "stopped io service" << std::endl;

        transport->detach();

        return  CommonAPI::CallStatus::SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

std::future<CommonAPI::CallStatus> ExampleInterfaceWampProxy::playAsync(PlayAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
	return CommonAPI::DBus::DBusProxyHelper<
		CommonAPI::DBus::DBusSerializableArguments<
		>,
		CommonAPI::DBus::DBusSerializableArguments<
		>
	>::callMethodAsync(
	*this,
	"play",
	"",
	(_info ? _info : &CommonAPI::DBus::defaultCallInfo),
	[_callback] (CommonAPI::CallStatus _status) {
		_callback(_status);
	},
	std::make_tuple());
}


void ExampleInterfaceWampProxy::getOwnVersion(uint16_t &ownVersionMajor, uint16_t &ownVersionMinor) const {
	ownVersionMajor = 0;
	ownVersionMinor = 0;
}

} // namespace example
