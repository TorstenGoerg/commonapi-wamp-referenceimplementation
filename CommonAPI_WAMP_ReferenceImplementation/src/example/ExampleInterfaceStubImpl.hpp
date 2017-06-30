
#include "generated/ExampleInterfaceStub.hpp"


namespace example {

class ExampleInterfaceStubImpl : public ExampleInterfaceStub
{
public:
    virtual RemoteEventHandlerType* initStubAdapter(const std::shared_ptr<StubAdapterType> &_stubAdapter);

    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId);

    /// This is the method that will be called on remote calls on the method play.
    virtual void play(const std::shared_ptr<CommonAPI::ClientId> _client, playReply_t _reply);
    /// This is the method that will be called on remote calls on the method add2.
    virtual void add2(const std::shared_ptr<CommonAPI::ClientId> _client, int64_t _left, int64_t _right, add2Reply_t _reply);
    /// This is the method that will be called on remote calls on the method add2struct.
    virtual void add2struct(const std::shared_ptr<CommonAPI::ClientId> _client, ExampleInterface::Summands _s, add2structReply_t _reply);
    /// This is the method that will be called on remote calls on the method add2nestedStruct.
    virtual void add2nestedStruct(const std::shared_ptr<CommonAPI::ClientId> _client, ExampleInterface::Params _p, add2nestedStructReply_t _reply);
};

} // namespace example
