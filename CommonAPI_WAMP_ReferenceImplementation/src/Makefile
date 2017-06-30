
all: ExampleCallee ExampleCaller


ExampleCallee: WampAddress.o WampAddressTranslator.o WampClientId.o WampError.o WampStubAdapter.o WampFactory.o WampConnection.o WampMainLoopContext.o WampMainLoop.o WampFunctionalHash.o MurmurHash3.o ExampleInterface.o ExampleInterfaceWampStubAdapter.o ExampleInterfaceWampStructsSupport.o ExampleInterfaceStubImpl.o ExampleCallee.o
	g++ -oExampleCallee \
	WampAddress.o \
	WampAddressTranslator.o \
	WampClientId.o \
	WampError.o \
	WampStubAdapter.o \
	WampFactory.o \
	WampConnection.o \
	WampMainLoopContext.o \
	WampMainLoop.o \
	WampFunctionalHash.o \
	MurmurHash3.o \
	ExampleInterface.o \
	ExampleInterfaceWampStubAdapter.o \
	ExampleInterfaceWampStructsSupport.o \
	ExampleInterfaceStubImpl.o \
	ExampleCallee.o \
	-lCommonAPI \
	-lboost_thread \
	-lboost_system \
	-lboost_program_options \
	-lmsgpackc

ExampleCaller: ExampleInterface.o ExampleInterfaceWampStructsSupport.o ExampleCaller.o
	g++ -oExampleCaller \
	ExampleInterface.o \
	ExampleInterfaceWampStructsSupport.o \
	ExampleCaller.o \
	-lboost_thread \
	-lboost_system \
	-lboost_program_options \
	-lmsgpackc

clean:
	rm *.o


# CommonAPI-Wamp runtime modules

WampAddress.o: runtime/CommonAPI/Wamp/WampAddress.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampAddress.cpp

WampAddressTranslator.o: runtime/CommonAPI/Wamp/WampAddressTranslator.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampAddressTranslator.cpp

WampClientId.o: runtime/CommonAPI/Wamp/WampClientId.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampClientId.cpp

WampError.o: runtime/CommonAPI/Wamp/WampError.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampError.cpp

WampStubAdapter.o: runtime/CommonAPI/Wamp/WampStubAdapter.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampStubAdapter.cpp

WampFactory.o: runtime/CommonAPI/Wamp/WampFactory.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampFactory.cpp

WampConnection.o: runtime/CommonAPI/Wamp/WampConnection.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampConnection.cpp

WampMainLoopContext.o: runtime/CommonAPI/Wamp/WampMainLoopContext.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampMainLoopContext.cpp

WampMainLoop.o: runtime/CommonAPI/Wamp/WampMainLoop.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampMainLoop.cpp

WampFunctionalHash.o: runtime/CommonAPI/Wamp/WampFunctionalHash.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/CommonAPI/Wamp/WampFunctionalHash.cpp


# external component MurmurHash

MurmurHash3.o: runtime/murmurhash/MurmurHash3.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c runtime/murmurhash/MurmurHash3.cpp


# CommonAPI-Wamp modules that shall be generated later on

ExampleInterface.o: example/generated/ExampleInterface.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -I. -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c example/generated/ExampleInterface.cpp

ExampleInterfaceWampStubAdapter.o: example/generated/ExampleInterfaceWampStubAdapter.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -I. -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c example/generated/ExampleInterfaceWampStubAdapter.cpp

ExampleInterfaceWampStructsSupport.o: example/generated/ExampleInterfaceWampStructsSupport.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -I. -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c example/generated/ExampleInterfaceWampStructsSupport.cpp


# handwritten example modules

ExampleInterfaceStubImpl.o: example/ExampleInterfaceStubImpl.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -I. -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c example/ExampleInterfaceStubImpl.cpp

ExampleCallee.o: example/ExampleCallee.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -I. -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c example/ExampleCallee.cpp

ExampleCaller.o: example/ExampleCaller.cpp
	g++ -Iruntime/ -I/usr/local/include/CommonAPI-3.1 -I. -DCOMMONAPI_INTERNAL_COMPILATION -std=c++11 -c example/ExampleCaller.cpp
