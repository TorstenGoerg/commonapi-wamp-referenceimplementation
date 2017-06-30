/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.3.v201507280808.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef EXAMPLE_Example_Interface_STUB_HPP_
#define EXAMPLE_Example_Interface_STUB_HPP_

#include <functional>




#include <example/ExampleInterface.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>
#include <vector>

#include <CommonAPI/Stub.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace example {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service ExampleInterface. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class ExampleInterfaceStubAdapter
    : virtual public CommonAPI::StubAdapter, 
      public ExampleInterface {
 public:



    virtual void deactivateManagedInstances() = 0;
protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for ExampleInterface.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class ExampleInterfaceStubRemoteEvent
{
public:
    virtual ~ExampleInterfaceStubRemoteEvent() { }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service ExampleInterface to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class ExampleInterfaceStub
    : public virtual CommonAPI::Stub<ExampleInterfaceStubAdapter, ExampleInterfaceStubRemoteEvent>
{
public:
    typedef std::function<void ()>playReply_t;
    typedef std::function<void (int64_t _sum, int64_t _diff)>add2Reply_t;
    typedef std::function<void (ExampleInterface::SumDiff _result)>add2structReply_t;
    typedef std::function<void (ExampleInterface::SumDiff _result)>add2nestedStructReply_t;

    virtual ~ExampleInterfaceStub() {}
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;


    /// This is the method that will be called on remote calls on the method play.
    virtual void play(const std::shared_ptr<CommonAPI::ClientId> _client, playReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method add2.
    virtual void add2(const std::shared_ptr<CommonAPI::ClientId> _client, int64_t _left, int64_t _right, add2Reply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method add2struct.
    virtual void add2struct(const std::shared_ptr<CommonAPI::ClientId> _client, ExampleInterface::Summands _s, add2structReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method add2nestedStruct.
    virtual void add2nestedStruct(const std::shared_ptr<CommonAPI::ClientId> _client, ExampleInterface::Params _p, add2nestedStructReply_t _reply) = 0;

    using CommonAPI::Stub<ExampleInterfaceStubAdapter, ExampleInterfaceStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<ExampleInterfaceStubAdapter, ExampleInterfaceStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<ExampleInterfaceStubAdapter, ExampleInterfaceStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef ExampleInterfaceStubRemoteEvent RemoteEventType;
    typedef ExampleInterface StubInterface;
};

} // namespace example

#endif // EXAMPLE_Example_Interface_STUB_HPP_
