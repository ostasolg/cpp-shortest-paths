//
// Created by ostasolg on 30.01.21.
//

#include "Graph.hpp"




/**
 * This function computes shortest path distances between all vertexes of provided graph's matrix
 * using single-threaded Floyd-Warshall algorithm.
 *
 * @return distances matrix.
 */
std::vector<std::vector<double>> Graph::floydWarshallSingle() {

    int number = Graph::matrixOfGraph.size();
    std::vector<std::vector<double>> distanceMatrix = Graph::matrixOfGraph;

    // loop over all intermediate nodes
    for (int k = 0; k < number; k++) {

        // loop over all starting nodes
        for (int i = 0; i < number; i++) {

            // loop over all ending nodes
            for (int j = 0; j < number; j++) {

                // If there is better path from vertex "i" to vertex "j" through vertex "k",
                // then update the shortest path.
                if (distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j]) {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                }
            }
        }
    }
    return distanceMatrix;
}



/**
 * This function computes shortest path distances between all vertexes of provided graph's matrix
 * using multi-threaded Floyd-Warshall algorithm.
 *
 * @return distance matrix
 */
std::vector<std::vector<double>> Graph::floydWarshallMulti() {

    int number = Graph::matrixOfGraph.size();
    std::vector<std::vector<double>> distanceMatrix = Graph::matrixOfGraph;

    // define number of threads to be used
    unsigned int numberOfThreads = std::thread::hardware_concurrency();

    // declaration of thread function
    auto threadFunc = [&] (int k, int threadNumber) {

        // loop over starting nodes
        for (unsigned int i = threadNumber; i < number; i += numberOfThreads) {

            // loop over ending nodes
            for (int j = 0; j < number; j++) {

                // If there is better path from vertex "i" to vertex "j" through vertex "k",
                // then update the shortest path.
                if (distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j]) {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                }
            }
        }
    };


    // vector to store computing threads
    std::vector<std::thread> threads;


    // loop over all intermediate nodes
    for (int k = 0; k < number; k++) {

        // run specified number of threads
        for (unsigned int threadNumber = 0; threadNumber < numberOfThreads; threadNumber++) {
            threads.emplace_back(threadFunc, k, threadNumber);
        }

        // let the main thread wait for all computational threads
        for (std::thread& thread : threads) {
            thread.join();
        }

        // clear vector of threads
        threads.clear();
    }
    return distanceMatrix;
}





/**
 * This function gets graph's matrix.
 *
 * @return matrix represented as a vector of another vector of double values.
 */
const std::vector<std::vector<double>> &Graph::getMatrixOfGraph() const {
    return matrixOfGraph;
}


/**
 * Constructor for Graph
 *
 * @input matrix represented as a vector of another vector of double values.
 */
Graph::Graph(const std::vector<std::vector<double>>& input) {
    matrixOfGraph = input;
}



