#include <iostream>
#include <memory>
#include <thread>

#include <CommonAPI/CommonAPI.hpp>
#include "ExampleInterfaceStubImpl.hpp"


#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class printer
{
public:
  printer(boost::asio::io_service& io)
    : strand_(io),
      timer1_(io, boost::posix_time::seconds(1)),
	  timer2_(io, boost::posix_time::seconds(1)),
      count_(0)
  {
    timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
    timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
  }

  ~printer()
  {
    std::cout << "Final count is " << count_ << std::endl;
  }

  void print1()
  {
    if (count_ < 5)
    {
      std::cout << count_ << std::endl;
      ++count_;

      timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(1));
      timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
    }
  }

  void print2()
  {
    if (count_ < 5)
    {
      std::cout << count_ << std::endl;
      ++count_;

      timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
      timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
    }
  }

private:
  boost::asio::io_service::strand strand_;
  boost::asio::deadline_timer timer1_;
  boost::asio::deadline_timer timer2_;
  int count_;
};

int main()
{
/*
	boost::asio::io_service io;

	printer p(io);
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
	io.run();
	t.join();

    std::cout << "finished" << std::endl;
//    std::cout << "Final count is " << count << std::endl;

	return 0;
*/


	std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

	std::string domain = "local";
	std::string instance = "commonapi.examples.HelloWorld";
	std::string connection = "service-sample";

	std::shared_ptr<example::ExampleInterfaceStubImpl> myService = std::make_shared<example::ExampleInterfaceStubImpl>();
	runtime->registerService(domain, instance, myService, connection);

	while (true) {
		std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(60));
	}

    return 0;
}
