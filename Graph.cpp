//
// Created by Octowhere on 12/3/2024.
//

#include "Graph.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

Graph::Graph() : numVertices(0), numEdges(0) {};

Graph::Graph(int vertices) : numVertices(vertices), numEdges(0) , adjacencyMatrix(vertices, std::vector<int>(vertices, INF)){
    for (int i = 0; i < vertices; i++) {
        adjacencyMatrix[i][i] = 0;
    }
};

bool Graph::loadFromFile(const std::string &filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return false;
    }

    infile >> numVertices;
    if(infile.eof()) {
        std::cerr << "Error reading verticies " << filename << std::endl;
        infile.close();
        return false;
    }

    infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    initializeMatrix();

    std::string line;
    for (int i = 0; i < numVertices; i++) {
        if(!std::getline(infile, line)) {
            std::cerr << "Error reading file. Not enough to complete matrix " << filename << std::endl;
            infile.close();
            return false;
        }

        std::istringstream iss(line);
        std::string value;
        for(int j = 0; j < numVertices; j++) {
            if(!(iss >> value)) {
                std::cerr << "Error reading file. Not enough elements in string " << filename << std::endl;
                infile.close();
                return false;
            }
            if(value == "INF"){
                adjacencyMatrix[i][j] = INF;
            }
            else{
                try{
                    adjacencyMatrix[i][j] = std::stoi(value);
                }
                catch(...){
                    std::cerr << "Incorrect format: " << value << "\n";
                    infile.close();
                    return false;
                }
            }
        }
    }
    infile.close();
    return true;
}

int Graph::getEdgeWeight(int src, int dest) const {
    return adjacencyMatrix[src][dest];
}

void Graph::initializeMatrix() {
    adjacencyMatrix.assign(numVertices, std::vector<int>(numVertices, INF));
    for(int i = 0; i < numVertices; ++i)
        adjacencyMatrix[i][i] = 0;
}

const std::vector<std::vector<int> > &Graph::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

int Graph::getNumVertices() const {
    return numVertices;
}

void Graph::printMatrix() const {
    std::cout << "\n=== Adjacency Matrix ===\n";
    int V = numVertices;

    std::cout << "    ";
    for(int j = 0; j < V; ++j){
        std::cout << std::setw(5) << j;
    }
    std::cout << "\n";

    std::cout << "    ";
    for(int j = 0; j < V; ++j){
        std::cout << "-----";
    }
    std::cout << "\n";

    for(int i = 0; i < V; ++i){
        std::cout << std::setw(3) << i << "|";
        for(int j = 0; j < V; ++j){
            if(adjacencyMatrix[i][j] == INF)
                std::cout << std::setw(5) << "INF";
            else
                std::cout << std::setw(5) << adjacencyMatrix[i][j];
        }
        std::cout << "\n";
    }
}




