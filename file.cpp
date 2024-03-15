#include <iostream>
#include <string>

int main() {
    std::string filePath;

    // Prompt the user to enter the file path for the text file
    std::cout << "Enter the file path for the text file (.txt): ";
    
    // Read the input from the terminal
    std::getline(std::cin, filePath);

    // Display the entered file path
    std::cout << "You entered: " << filePath << std::endl;

    return 0;
}

