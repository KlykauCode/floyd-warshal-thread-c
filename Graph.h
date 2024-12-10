//
// Created by Octowhere on 12/3/2024.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <limits>
#include <string>
#include <vector>

const int INF = std::numeric_limits<int>::max();

class Graph {
private:
    int numVertices;
    int numEdges;
    std::vector<std::vector<int>> adjacencyMatrix;
public:
    Graph();
    Graph(int vertices);

    bool loadFromFile(const std::string &filename);

    int getNumVertices() const;
    const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

    int getEdgeWeight(int src, int dest) const;

    void initializeMatrix();

    void printMatrix() const;
};



#endif //GRAPH_H
