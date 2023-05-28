# Server Application

This is a simple server application written in C++ using the Boost.Asio library. It provides a TCP server that listens on a specified port and responds to client connections.

## Requirements

- C++ compiler with C++11 support
- Boost library (version 1.72 or later)

## Usage

1. Clone or download the repository to your local machine.
2. Ensure that you have the Boost library installed and properly configured in your development environment.
3. Open a terminal or command prompt and navigate to the project directory.
4. Compile the source code using the C++ compiler. For example:
   ```
   g++ server.cpp -o server -lboost_system -std=c++11
   ```
   Note: Adjust the compiler and linker flags based on your specific environment and configuration.
5. Run the compiled server binary. For example:
   ```
   ./server
   ```
6. The server will start listening on a specified port (default: 12345). It will display a message when a client connects and send a "Hello, client!" message to the client.
7. To terminate the server, press Ctrl+C in the terminal or command prompt.

## Configuration

By default, the server listens on port 12345. If you want to change the listening port, modify the `port` variable in the `main` function of the `server.cpp` file.

```cpp
int main() {
  // ...

  // Specify the port number to listen on
  short port = 12345;

  Server server(io_service, port);

  // ...
}
```

## Troubleshooting

- If you encounter any compilation errors related to Boost.Asio, ensure that you have the Boost library properly installed and that the necessary header files and libraries are accessible to the compiler.
- If you experience issues with running the server, make sure that the specified port is not being used by another application or blocked by a firewall.

## Contributing

Contributions to this project are welcome. Feel free to submit bug reports, feature requests, or pull requests.

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code as permitted by the license.

## Acknowledgments

This server application is built using the Boost.Asio library, which provides a powerful and flexible framework for network programming in C++. Special thanks to the Boost community for their contributions and support.

---