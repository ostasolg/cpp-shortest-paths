//
// Created by ostasolg on 30.01.21.
//

#ifndef OSTASOLG_SEMESTRALKA_GRAPH_HPP
#define OSTASOLG_SEMESTRALKA_GRAPH_HPP
#include <iostream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
#include <limits>
#include<thread>

/* Define Infinite which will be used for representation of
vertices not connected to each other. */
#define INF std::numeric_limits<double>::infinity()


class Graph {
private:

    std::vector<std::vector<double>> matrixOfGraph;


public:

    explicit Graph(const std::vector<std::vector<double>>& input);

    ~Graph()= default;

    std::vector<std::vector<double>> floydWarshallSingle();
    std::vector<std::vector<double>> floydWarshallMulti();

    const std::vector<std::vector<double>> &getMatrixOfGraph() const;
};


#endif //OSTASOLG_SEMESTRALKA_GRAPH_HPP
