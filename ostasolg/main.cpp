
// C++ Program for Floyd-Warshall Algorithm
#include <bits/stdc++.h>
#include <fstream>
#include "utils.hpp"



int main(int argc, char *argv[]) {

    if (argc > 1) {

        // Check if the second argument is '--help'.
        if (argc == 2 && std::string(argv[1]) == "--help") {
            // write program's description.
            writeProgramDescriptionToConsole(std::cout);
            exit(0);
        }
        if (argc == 3) {
            // Use single-threaded algorithm.
            std::string inputFileName = std::string(argv[1]);
            Graph graph = readGraphFromFile(inputFileName);
            std::vector<std::vector<double>> resultMatrix = graph.floydWarshallSingle();
            std::string outputFileName = std::string(argv[2]);
            writeDistanceMatrixToFile(resultMatrix, outputFileName);
            exit(0);
        }

        // Check if the first argument is '-m'.
        if (argc == 4 && std::string(argv[1]) == "-m") {
            // Use multi-threaded algorithm.
            std::string inputFileName = std::string(argv[2]);
            Graph graph = readGraphFromFile(inputFileName);
            std::vector<std::vector<double>> resultMatrix = graph.floydWarshallMulti();
            std::string outputFileName = std::string(argv[3]);
            writeDistanceMatrixToFile(resultMatrix, outputFileName);
            exit(0);
        }

        else {
            // Wrong input program parameters, program will write its description.
            writeProgramDescriptionToConsole(std::cout);
            exit(1);

        }
    } else {
        // Wrong input program parameters, program will write its description.
        writeProgramDescriptionToConsole(std::cout);
        exit(1);
    }
}