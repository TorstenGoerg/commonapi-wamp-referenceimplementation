
#include "ExampleInterfaceStubImpl.hpp"

#include <iostream>


namespace example {

ExampleInterfaceStubImpl::RemoteEventHandlerType* ExampleInterfaceStubImpl::initStubAdapter(const std::shared_ptr<ExampleInterfaceStubImpl::StubAdapterType> &_stubAdapter) {
	return nullptr;
}

static const CommonAPI::Version version(0, 0);

const CommonAPI::Version& ExampleInterfaceStubImpl::getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) {
	return version;
}

void ExampleInterfaceStubImpl::play(const std::shared_ptr<CommonAPI::ClientId> _client, playReply_t _reply) {
    std::cout << "ExampleInterfaceStubImpl::play called" << std::endl;
}

void ExampleInterfaceStubImpl::add2(const std::shared_ptr<CommonAPI::ClientId> _client, int64_t _left, int64_t _right, add2Reply_t _reply) {
    std::cout << "ExampleInterfaceStubImpl::add2 called" << std::endl;
    _reply(_left+_right, _left-_right);
}

void ExampleInterfaceStubImpl::add2struct(const std::shared_ptr<CommonAPI::ClientId> _client, ExampleInterface::Summands _s, add2structReply_t _reply) {
    std::cout << "ExampleInterfaceStubImpl::add2struct called" << std::endl;
    ExampleInterface::SumDiff result;
    result.setSum(_s.getLeft()+_s.getRight());
    result.setDiff(_s.getLeft()-_s.getRight());
    _reply(result);
}

void ExampleInterfaceStubImpl::add2nestedStruct(const std::shared_ptr<CommonAPI::ClientId> _client, ExampleInterface::Params _p, add2nestedStructReply_t _reply) {
    std::cout << "ExampleInterfaceStubImpl::add2nestedStruct called" << std::endl;
    ExampleInterface::SumDiff result;
    result.setSum(_p.getSs().getLeft()+_p.getSs().getRight());
    result.setDiff(_p.getSs().getLeft()-_p.getSs().getRight());
    _reply(result);
}

} // namespace example
