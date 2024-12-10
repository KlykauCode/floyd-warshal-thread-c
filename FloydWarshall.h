//
// Created by Octowhere on 12/3/2024.
//

#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H
#include <vector>

#include "Graph.h"


class FloydWarshall {
protected:
    Graph graph;
    std::vector<std::vector<int>> distances;
    std::vector<std::vector<int>> predecessors;

public:
    static const int INF;
    FloydWarshall(const Graph& graph);

    virtual ~FloydWarshall() = default;
    virtual void compute() = 0;

    const std::vector<std::vector<int>>& getDistances() const;
    const std::vector<std::vector<int>>& getPredecessors() const;

    void printDistances() const;
    void printPath(int src, int dest) const;
};



#endif //FLOYDWARSHALL_H
