#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::ifstream takeInputFromFile(const char* fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening input file: " << fileName << std::endl;
    }
    return inputFile;
}

void writeOutputToFile(const char* fileName, const std::string& outputData) {
    std::ofstream outputFile(fileName); 
    if (!outputFile) {
        std::cerr << "Error opening output file: " << fileName << std::endl;
    } else {
        // write to file
        outputFile << outputData;
        std::cout << "Output written to file: " << fileName << std::endl;
    }
    outputFile.close();
}

int main() {
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";

    // Take the input from a file
    std::ifstream inputStream = takeInputFromFile(inputFileName);

    // Process the input (this is a placeholder for actual processing logic)
    std::string line;
    std::vector<int> numbers;
    std::for_each(std::istream_iterator<int>(inputStream), std::istream_iterator<int>(), [&](int number) {
        numbers.push_back(number * 2);
    }); 

    // Output the numbers read from the file
    std::cout << "Numbers read from file: ";
    for (const int& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    
    // Write the output to a file
    std::string outputData;
    for (const int& number : numbers) {
        outputData += std::to_string(number) + "\n";
    }
    writeOutputToFile(outputFileName, outputData);
    
    inputStream.close();
    return 0;
}