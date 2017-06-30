/*
 * ExampleInterfaceWampProxy.hpp
 *
 *  Created on: May 18, 2017
 *      Author: vagrant
 */

#ifndef EXAMPLE_Example_Interface_WAMP_PROXY_HPP_
#define EXAMPLE_Example_Interface_WAMP_PROXY_HPP_

#include <example/ExampleInterfaceProxyBase.hpp>
// #include "example/ExampleInterfaceWampDeployment.hpp"

#include <string>

namespace example {

class ExampleInterfaceWampProxy
    : virtual public ExampleInterfaceProxyBase /*,
      virtual public CommonAPI::DBus::DBusProxy */ {
public:
    ExampleInterfaceWampProxy(
		const boost::asio::ip::tcp::endpoint &rawsocketEndpoint,
		const std::string &realm,
		bool debug);

    virtual ~ExampleInterfaceWampProxy() {}


    virtual void play(CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info);
    virtual std::future<CommonAPI::CallStatus> playAsync(PlayAsyncCallback _callback, const CommonAPI::CallInfo *_info);


    virtual void getOwnVersion(uint16_t &ownVersionMajor, uint16_t &ownVersionMinor) const;

private:
    boost::asio::ip::tcp::endpoint m_rawsocketEndpoint;
    std::string m_realm;
    bool m_debug;


};

} // namespace example


#endif // EXAMPLE_Example_Interface_WAMP_PROXY_HPP_
