//
// Created by ostasolg on 30.01.21.

#include "utils.hpp"



/**
 * This function reads adjacency matrix of the graph from provided text file and creates a Graph instance.
 *
 * @return Graph instance.
 */
Graph readGraphFromFile(std::string& fileName) {

    // Vector which represents the adjacency matrix of the graph.
    std::vector<std::vector<double>> matrix;

    // Read input graph adjacency matrix from the text file.
    std::ifstream myReadFile(fileName);

    // If no input file provided.
    if (!myReadFile) {
        std::cout << "Unable to open file.";
        exit(1); // Terminate with error.
    }


    std::string line;

    // Read the file line by line.
    while (getline (myReadFile, line)) {

        std::vector<double> row;

        std::string value;
        std::stringstream lineStringStream(line);

        // Loop over all values in line.
        while (std::getline(lineStringStream, value, ' ')) {
            if (value == "INF") {
                // Push INF value to the row of matrix.
                row.push_back(INF);
            } else {
                // Parse string to double and push the value to the row of matrix.
                row.push_back(std::stod(value));
            }
        }
        // Push the row to the matrix.
        matrix.push_back(row);
    }
    // Create and return Graph instance.
    Graph G(matrix);
    return G;
}


/**
 * This function writes provided graph's distance matrix to the text file.
 *
 * @param matrix - distance matrix to be written to the file.
 * @param fileName - name of file to which the distance matrix will be written.
 */
void writeDistanceMatrixToFile(const std::vector<std::vector<double>>& matrix, std::string& fileName) {

    // Create and open a text file.
    std::ofstream MyWriteFile(fileName);

    // Write to the file.
    MyWriteFile << "The following matrix shows the shortest distances between every pair of vertices.\n";
    MyWriteFile << "\n";


    int number = matrix.size();


    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {

            if (j + 1 == number) {

                if (matrix.at(i).at(j) == INF) {
                    MyWriteFile << "INF";
                } else {
                    MyWriteFile << matrix.at(i).at(j);
                }
            } else {

                if (matrix.at(i).at(j) == INF) {
                    MyWriteFile << "INF" << "  |  ";
                } else {
                    MyWriteFile << matrix.at(i).at(j) << "  |  ";
                }
            }
        }
        MyWriteFile<<std::endl;
    }

    // Close the file.
    MyWriteFile.close();
}


/**
 * This function writes the basic description of the application to the console.
 *
 * @param os - output stream reference.
 */
void writeProgramDescriptionToConsole(std::ostream& os) {

    os  << "Welcome to the Floyd-Warshall Algorithm implementation for solving Graph's shortest path problems."
        << "Options:\n"
        << "\t--help\t\tShow help message and exit.\n"
        << "\t-m\t\tRun the algorithm in multi-threaded mode.\n\n"
        << "Program description:\n"
        << "\tProgram reads the adjacency matrix, representing the input graph, from provided file and computes "
        "the shortest path distance between all nodes in the graph, using the Floyd–Warshall algorithm."
        "Computation algorithm may be run in a single or multi-threaded mode, depending on specified option. "
        "The results are written in a form of distance matrix to the output file.\n\n"
        << "Input data file format description:\n"
        << "\tProgram expects the input data file with the values of adjacency matrix representing the input graph. "
        "Each row must be on a separate line and the values in the rows must be separated by space. "
        "Adjacency matrix must be a square matrix with the size equal to the number of vertexes in the graph. "
        "Each element [i, j] of the adjacency matrix represents a distance between graph vertexes 'i' and 'j'. "
        "If there is no edge between two vertexes, then its distance in adjacency matrix must be specified as 'INF' "
        "(infinity).\n\n"
        << "Output data file format description:\n"
        << "\tProgram computes the shortest path distance between all vertexes of the graph and writes them "
        "to the output file in the form of distance matrix. Each value of the distance matrix [i, j] represents "
        "the shortest path distance from vertex 'i' to vertex 'j'. Each row of the distance matrix is on a separate "
        "line and the values in the rows are separated by '|'. Distance matrix is always a square matrix "
        "with the size equal to the number of vertexes in the graph. If there is no path from one vertex to another "
        "then its distance in the distance matrix is specified as 'INF' (infinity).\n\n"
        << "Example of input file:\n"
        << "0 3 INF 7\n"
        "8 0 2 INF\n"
        "5 INF 0 1\n"
        "2 INF INF 0\n\n"
        << "Example of output file:\n"
        << "0 3 5 6\n"
        "5 0 2 3\n"
        "3 6 0 1\n"
        "2 5 7 0\n\n"
        << std::endl;
}


/**
 * This function generates a random matrix of graph with specified number of vertexes.
 *
 * @param numberOfVertexes.
 */
std::vector<std::vector<double>> generateRandomMatrixOfGraph(int numberOfVertexes) {
    std::vector<std::vector<double>> matrix(numberOfVertexes, std::vector<double>(numberOfVertexes));

    for (int i = 0; i < numberOfVertexes; i++) {
        for (int j = 0; j < numberOfVertexes; j++) {
            matrix[i][j] = rand();
        }
    }
    return matrix;
}