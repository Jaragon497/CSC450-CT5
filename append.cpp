#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

void appendToFile(const std::string &file) {

    std::string userInput;
    std::ofstream modFile;

    // Open the file in append mode
    modFile.open(file, std::ios::app);

    // Throw error if file fails to open
    if (!modFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Get user input
    //  & append to file
    std::cout << "Enter text to append to file: ";
    std::getline(std::cin, userInput);
    modFile << userInput << std::endl;

    // Close the file and provide feedback for user
    modFile.close();
    std::cout << "Successfully appended text to file!" << std::endl;
}

void reverseFile(const std::string &origin, const std::string &dest) {

    std::ifstream inputFile(origin);
    std::ofstream outputFile(dest);

    // Throw error if either file cannot be opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        inputFile.close();
        return;
    }

    std::string content;
    std::string line;

    // Create a string by reading lines of file
    // End every line with a newline
    while (std::getline(inputFile, line)) {
        content += line;
        content += "\n";
    }

    // Remove any hanging newlines
    if (!content.empty() && content.back() == '\n') {
        content.pop_back();
    }

    // Reverse the string and store in file
    std::reverse(content.begin(), content.end());
    outputFile << content;

    // Close files and provide feedback for user
    inputFile.close();
    outputFile.close();

    std::cout << "Contents of `CSC450_CT5_mod5.txt` have been reversed and "
                 "stored in `CSC450-mod5-reverse.txt`";
}

int main() {
    std::string mainFile = "CSC450_CT5_mod5.txt";
    std::string revFile = "CSC450-mod5-reverse.txt";

    appendToFile(mainFile);
    reverseFile(mainFile, revFile);
}
