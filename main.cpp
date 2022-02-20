#include <boost/asio.hpp>
#include <boost/log/trivial.hpp>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main() {

  BOOST_LOG_TRIVIAL(info) << "starting";
  boost::asio::io_context ioc;

  boost::asio::steady_timer timer(ioc);
  timer.expires_from_now(1s);

  timer.async_wait([](boost::system::error_code ec) {
    BOOST_LOG_TRIVIAL(info) << "done";
  });

  ioc.run();

  return 0;
}
