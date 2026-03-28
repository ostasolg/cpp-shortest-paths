//
// Created by olinka on 30.01.21.
//


// C++ Program for Floyd-Warshall Algorithm
#include <bits/stdc++.h>
#include <fstream>
#include "utils.hpp"
#include <chrono>




template <typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}



int main(int argc, char *argv[]) {


    // Define default number of vertexes.
    int numberOfVertexes = 1000;

    // If program input parameter is provided.
    if (argc > 1) {
        // Set number of vertexes.
        numberOfVertexes = std::stoi(argv[1]);
    }
    std::cout << "Size of graph: " << numberOfVertexes << std::endl;

    try {

        // generate random graph with a specified number of nodes.
        std::vector<std::vector<double>> matrix = generateRandomMatrixOfGraph(numberOfVertexes);
        Graph graph(matrix);

        // Perform single threaded Floyd-Warshall algorithm.
        auto startS = std::chrono::high_resolution_clock::now();
        graph.floydWarshallSingle();
        auto endS = std::chrono::high_resolution_clock::now();
        std::cout << "Needed " << to_ms(endS - startS).count() << " ms to finish program in a single-threaded mode.\n";

        // Perform multi threaded Floyd-Warshall algorithm.
        auto startM = std::chrono::high_resolution_clock::now();
        graph.floydWarshallMulti();
        auto endM = std::chrono::high_resolution_clock::now();
        std::cout << "Needed " << to_ms(endM - startM).count() << " ms to finish program in a multi-threaded mode.\n";

    } catch (...) {
        std::cerr << "Unexpected error occurred" << std::endl;
        exit(1);
    }
}

