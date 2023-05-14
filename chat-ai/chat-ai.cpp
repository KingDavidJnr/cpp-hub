#include <iostream>
#include <string>
#include <curl/curl.h>

// Function to send HTTP request to OpenAI API
std::string sendRequest(const std::string& apiKey, const std::string& message) {
    // URL endpoint for the OpenAI API
    std::string url = "https://api.openai.com/v1/engines/davinci-codex/completions";
    
    // Set up the request payload with the API key and message
    std::string payload = R"({"prompt":")" + message + R"(","max_tokens":50})";

    // Initialize libcurl
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set the API endpoint URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set the request headers
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Set the request payload
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        // Store the response in a string
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* data, size_t size, size_t nmemb, std::string* response) {
            response->append(data, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Send the HTTP POST request
        CURLcode res = curl_easy_perform(curl);

        // Clean up libcurl
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);

        // Return the response
        return (res == CURLE_OK) ? response : "";
    }

    return "";
}

int main() {
    std::string apiKey = "YOUR_API_KEY"; // Replace with your OpenAI API key
    std::string chatHistory = ""; // Initialize the chat history

    std::cout << "Welcome to Chat AI!" << std::endl;

    while (true) {
        // Prompt the user for input
        std::string userInput;
        std::cout << "User: ";
        std::getline(std::cin, userInput);

        // Add the user's message to the chat history
        chatHistory += "User: " + userInput + "\n";

        // Exit the program if the user enters "exit"
        if (userInput == "exit") {
            break;
        }

        // Send the request to the OpenAI API
        std::string response = sendRequest(apiKey, chatHistory);

        // Extract the AI's reply from the response
        std::size_t startPos = response.find("\"choices\":[{\"text\":\"") + 20;
        std::size_t endPos = response.find("\"}],\"usage\":");
        std::string aiReply = response.substr(startPos, endPos - startPos);

        // Add the AI's reply to the chat history
        chatHistory += "AI: " + aiReply + "\n";

        // Display the AI's reply
        std::cout << "AI: " << aiReply << std::endl;
    }

    return 0;
}
