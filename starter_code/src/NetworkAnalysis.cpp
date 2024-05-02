#include "NetworkAnalysis.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


void dfs(int node, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    std::cout << "Visiting node " << node << "\n";
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}



char* NetworkAnalysis::getNetworkStatus(char* inputFilePath) {
    std::ifstream inFile(inputFilePath);
    if (!inFile) {
        char message[1024];
        sprintf(message, "Cannot open input file for reading: %s", inputFilePath);
        throw std::ios_base::failure(message);
    }

    int numberOfNodes;
    std::string line;
    std::getline(inFile, line);
    numberOfNodes = std::stoi(line.substr(line.find('=') + 1)); // Extract the number of nodes from the input file


    std::vector<std::vector<int>> adjList(numberOfNodes + 1);
    int node1, node2;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        char comma;
        ss >> node1 >> comma >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    inFile.close();

    std::vector<bool> visited(numberOfNodes + 1, false);


    std::cout << "Input file contents:\n";
    std::ifstream inputFile(inputFilePath);
    while (std::getline(inputFile, line)) {
        std::cout << line << "\n";
    }
    inputFile.close();

    std::cout << "\nAdjacency list:\n";
    for (int node = 1; node < adjList.size(); ++node) {
        std::cout << node << ": ";
        for (int neighbor : adjList[node]) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }


    dfs(1, adjList, visited);


    for (int node = 1; node <= numberOfNodes; ++node) {
        if (!visited[node]) {
            return "NO";
        }
    }

    return "YES";
}


// int main() {
//     try {
//         const char* inputFilePaths[] = {
//             "../sample_inputs/1_sample.txt",
//             "../sample_inputs/2_sample.txt",
//             "../sample_inputs/3_sample.txt"
//         };
//         const char* outputFilePaths[] = {
//             "../output1.txt",
//             "../output2.txt",
//             "../output3.txt"
//         };
//         const char* expectedAnswers[] = {"NO", "YES", "NO"};

//         for (int i = 0; i < 3; ++i) {
//             const char* networkStatus = NetworkAnalysis::getNetworkStatus(const_cast<char*>(inputFilePaths[i]));

//             std::ofstream outputFile(outputFilePaths[i]);
//             if (outputFile.is_open()) {
//                 outputFile << "Network status: " << networkStatus << '\n';
//                 outputFile.close();
//                 std::cout << "Connected items processed successfully for " << inputFilePaths[i] << ". Output written to " << outputFilePaths[i] << std::endl;

//                 if (std::string(networkStatus) != std::string(expectedAnswers[i])) {
//                     std::cerr << "Error: Expected answer for " << inputFilePaths[i] << " is " << expectedAnswers[i] << ", but got " << networkStatus << std::endl;
//                 }
//             } else {
//                 std::cerr << "Error: Unable to open output file " << outputFilePaths[i] << std::endl;
//             }
//         }
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }