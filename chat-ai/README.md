# Chat AI App

The Chat AI app is a simple console-based application that allows you to have conversations with an AI powered by the OpenAI API. You can enter messages, and the AI will provide responses based on the conversation history.

## Prerequisites

- C++ Compiler: Make sure you have a C++ compiler installed on your system. For example, you can use GCC or Clang.

- libcurl Library: The Chat AI app relies on the libcurl library to make HTTP requests. Ensure that libcurl is installed on your system before compiling and running the application.

- OpenAI API Key: To use the Chat AI app, you need an API key from the OpenAI API. Obtain an API key from the OpenAI website before proceeding.

## Getting Started

Follow the instructions below to compile and run the Chat AI app on your local machine.

1. Clone the repository or download the source code files to your computer.

2. Open a terminal or command prompt and navigate to the directory where the Chat AI source code files are located.

3. Open the `chat_ai.cpp` file in a text editor and replace `"YOUR_API_KEY"` in the `API_KEY` variable with your actual OpenAI API key.

4. Compile the code using the following command:

   ```bash
   g++ -o chat_ai chat_ai.cpp -lcurl
   ```

   This command will generate an executable file named `chat_ai`.

5. Run the program by executing the following command:

   ```bash
   ./chat_ai
   ```

6. The Chat AI app will display a welcome message and wait for your input.

7. Enter your message as the user, and the AI will respond accordingly based on the conversation history.

8. To exit the program, simply enter "exit".

## Example Usage

Here's an example of how a conversation might look using the Chat AI app:

```
Welcome to Chat AI!
User: Hello, how are you?
AI: I'm doing well. How can I assist you today?
User: Can you tell me a joke?
AI: Sure! Why don't scientists trust atoms? Because they make up everything!
User: Haha, that's a good one!
AI: I'm glad you liked it!
User: Thank you. Goodbye!
AI: Goodbye! Have a great day!
```

In this example, the user initiates the conversation with a greeting, asks for a joke, and then ends the conversation by saying goodbye.

## Contributing

Contributions to this project are welcome. If you have any suggestions, improvements, or encounter any issues, please submit a pull request or open an issue.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code for personal or commercial purposes.

## Acknowledgments

This project was inspired by the goal of creating a simple and interactive application to demonstrate the capabilities of the OpenAI API.

## Conclusion

The Chat AI app provides an interactive way to have conversations with an AI using the OpenAI API. By following the instructions in this README, you can compile and run the application on your local machine. Feel free to modify and enhance the code to suit your specific requirements.

If you have any questions or encounter any issues, please don't hesitate to reach out. Enjoy conversing with the AI!