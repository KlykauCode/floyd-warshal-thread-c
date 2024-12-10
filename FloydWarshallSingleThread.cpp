//
// Created by Octowhere on 12/3/2024.
//

#include "FloydWarshallSingleThread.h"

#include "FloydWarshallMultiThread.h"

FloydWarshallSingleThread::FloydWarshallSingleThread(const Graph &g) : FloydWarshall(g) {};

void FloydWarshallSingleThread::compute() {
    int V = graph.getNumVertices();
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                if(distances[i][k] < INF && distances[k][j] < INF){
                    if(distances[i][k] + distances[k][j] < distances[i][j]){
                        distances[i][j] = distances[i][k] + distances[k][j];
                        predecessors[i][j] = predecessors[k][j];
                    }
                }
            }
        }
    }
}


