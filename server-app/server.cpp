#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Server {
public:
  Server(boost::asio::io_service& io_service, short port)
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
      socket_(io_service) {
    startAccept();
  }

private:
  void startAccept() {
    acceptor_.async_accept(socket_,
      [this](boost::system::error_code ec) {
        if (!ec) {
          std::cout << "Connection established!" << std::endl;
          std::string message = "Hello, client!";
          boost::asio::async_write(socket_,
            boost::asio::buffer(message),
            [this](boost::system::error_code ec, std::size_t /*length*/) {
              if (!ec) {
                std::cout << "Message sent to the client." << std::endl;
              }
              else {
                std::cerr << "Failed to send message to the client: " << ec.message() << std::endl;
              }
            }
          );
        }
        startAccept();
      }
    );
  }

  tcp::acceptor acceptor_;
  tcp::socket socket_;
};

int main() {
  try {
    boost::asio::io_service io_service;
    Server server(io_service, 12345);
    io_service.run();
  }
  catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  
  return 0;
}
