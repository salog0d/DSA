#include <iostream>
#include <string>

int main() {
    // Creating a string
    std::string str1 = "Hello, World!";
    std::cout << "str1: " << str1 << std::endl;

    // Copying a string
    std::string str2 = str1;
    std::cout << "str2: " << str2 << std::endl;

    // Concatenating strings
    std::string str3 = str1 + " How are you?";
    std::cout << "str3: " << str3 << std::endl;

    // Getting the length of a string
    std::cout << "Length of str1: " << str1.length() << std::endl;

    // Accessing characters in a string
    std::cout << "First character of str1: " << str1[0] << std::endl;

    // Modifying characters in a string
    str1[0] = 'h';
    std::cout << "Modified str1: " << str1 << std::endl;

    // Substring
    std::string str4 = str1.substr(0, 5);
    std::cout << "Substring of str1: " << str4 << std::endl;

    // Finding a substring
    size_t pos = str1.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl;
    } else {
        std::cout << "'World' not found" << std::endl;
    }

    // Erasing part of a string
    str1.erase(0, 6);
    std::cout << "Erased str1: " << str1 << std::endl;

    // Inserting into a string
    str1.insert(0, "Hello, ");
    std::cout << "Inserted str1: " << str1 << std::endl;

    // Clearing a string
    str1.clear();
    std::cout << "Cleared str1: " << str1 << std::endl;

    // Checking if a string is empty
    if (str1.empty()) {
        std::cout << "str1 is empty" << std::endl;
    }

    return 0;
}