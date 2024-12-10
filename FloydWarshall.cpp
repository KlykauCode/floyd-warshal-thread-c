//
// Created by Octowhere on 12/3/2024.
//

#include "FloydWarshall.h"

#include <iomanip>
#include <iostream>

const int FloydWarshall::INF = std::numeric_limits<int>::max();

FloydWarshall::FloydWarshall(const Graph& g) : graph(g), distances(g.getAdjacencyMatrix()), predecessors(g.getNumVertices(), std::vector<int>(g.getNumVertices(), -1)) {
    int V = graph.getNumVertices();
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(graph.getEdgeWeight(i, j) != INF && i != j){
                predecessors[i][j] = i;
            }
        }
    }
}

const std::vector<std::vector<int>>& FloydWarshall::getPredecessors() const {
    return predecessors;
}

const std::vector<std::vector<int> > &FloydWarshall::getDistances() const {
    return distances;
}

void FloydWarshall::printDistances() const {
    std::cout << "\n=== Distance Matrix ===\n";
    int V = graph.getNumVertices();
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
            if(distances[i][j] == INF)
                std::cout << std::setw(5) << "INF";
            else
                std::cout << std::setw(5) << distances[i][j];
        }
        std::cout << "\n";
    }
}

void FloydWarshall::printPath(int src, int dest) const {
    if(distances[src][dest] == INF){
        std::cout << "No path from " << src << " to " << dest << ".\n";
        return;
    }

    std::vector<int> path;
    int current = dest;
    while(current != src){
        if(current == -1){
            std::cout << "No path exists.\n";
            return;
        }
        path.push_back(current);
        current = predecessors[src][current];
    }
    path.push_back(src);

    // Print path in reverse order
    std::cout << "Path from " << src << " to " << dest << ": ";
    for(auto it = path.rbegin(); it != path.rend(); ++it){
        std::cout << *it;
        if(it + 1 != path.rend()){
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

