//
// Created by olinka on 30.01.21.
//

#ifndef OSTASOLG_SEMESTRALKA_UTILS_HPP
#define OSTASOLG_SEMESTRALKA_UTILS_HPP

#include <bits/stdc++.h>
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <utility>


/* Define Infinite which will be used for representation of
vertices not connected to each other. */
#define INF std::numeric_limits<double>::infinity()


std::vector<std::vector<double>> generateRandomMatrixOfGraph(int numberOfVertexes);
Graph readGraphFromFile(std::string& fileName);
void writeDistanceMatrixToFile(const std::vector<std::vector<double>>& matrix, std::string& fileName);
void writeProgramDescriptionToConsole(std::ostream& cout);


#endif //OSTASOLG_SEMESTRALKA_UTILS_HPP