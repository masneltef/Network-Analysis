/**
 * @file NetworkAnalysis.h
 * @brief This header file defines the NetworkAnalysis class and its member functions for analyzing the connectivity of a network.
 *
 * The NetworkAnalysis class provides a static function `getNetworkStatus` that takes an input file path as an argument
 * and determines whether the network represented by the input file is fully connected or not.
 *
 * The program works as follows:
 *
 * 1. The main function reads the input file paths, output file paths, and expected answers from predefined arrays.
 * 2. It iterates over these arrays and calls the `getNetworkStatus` function for each input file.
 * 3. The `getNetworkStatus` function constructs an adjacency list representation of the network from the input file.
 * 4. It performs a depth-first search (DFS) traversal starting from node 1 using the `dfs` function.
 * 5. If all nodes are visited during the DFS, the network is fully connected, and the function returns "YES".
 * 6. Otherwise, it returns "NO".
 * 7. The main function writes the network status to the corresponding output file and compares it with the expected answer.
 *
 * The input file should have the following format:
 * - The first line specifies the number of nodes in the network, in the format "numberOfNodes = X".
 * - Each subsequent line represents an edge in the network, with two node numbers separated by a comma.
 *
 * If the input file cannot be read, the function throws an exception of type `std::ios_base::failure`.
 *
 * The class also includes necessary headers for input/output operations, memory usage tracking, and logging.
 *
 *
 *
 * @file main.cpp
 * @brief This file contains the main function and the implementation of the `dfs` function.
 *
 * The main function is the entry point of the program and handles the following tasks:
 *
 * 1. It defines arrays for the input file paths, output file paths, and expected answers.
 * 2. It iterates over these arrays and calls the `getNetworkStatus` function from the NetworkAnalysis class for each input file.
 * 3. It writes the network status obtained from `getNetworkStatus` to the corresponding output file.
 * 4. It compares the obtained network status with the expected answer and prints an error message if they don't match.
 * 5. It handles any exceptions that may occur during the execution of the program.
 *
 * The `dfs` function is a helper function used by the `getNetworkStatus` function in the NetworkAnalysis class.
 * It performs a depth-first search (DFS) traversal on the graph represented by the adjacency list.
 * It takes the following arguments:
 *
 * - `node`: The starting node for the DFS traversal.
 * - `adjList`: The adjacency list representation of the graph.
 * - `visited`: A vector to keep track of the visited nodes during the DFS traversal.
 *
 * The `dfs` function recursively visits all unvisited neighbors of a node and marks them as visited.
 * It is used by the `getNetworkStatus` function to determine if all nodes in the network are connected.
 *
 * @author Yvan Masnel Tefiang
 * @date 02/05/2024
 */


#ifndef NETWORKANALYSIS_H
#define NETWORKANALYSIS_H

#include <iostream>
#include <fstream>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include "./util/GetMemUsage.h"
#include "./util/LogManager.h"

class NetworkAnalysis{


public:
	/**
	 *
	 *
	 * @param inputFilePath Path of the input file.
	 *
	 * If the input file cannot be read throw an error of type ios_base::failure
	 * Status should be displayed on the screen
	 */
	static char* getNetworkStatus(char* inputFilePath);
};

#endif /* NETWORKANALYSIS_H */
