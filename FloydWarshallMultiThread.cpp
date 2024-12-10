//
// Created by Octowhere on 12/3/2024.
//

#include "FloydWarshallMultiThread.h"

FloydWarshallMultiThread::FloydWarshallMultiThread(const Graph &g, int num_threads) : FloydWarshall(g), num_threads(num_threads) {}

void FloydWarshallMultiThread::compute() {
    int V = graph.getNumVertices();

    for (int k = 0; k < V; ++k) {
        std::vector<std::thread> threads; // vector pro vlakna
        int chunk_size = (V + num_threads - 1) / num_threads; // diapazona vrcholu i s kterymi bude pracovat vlakno

        for (int t = 0; t < num_threads; ++t) {
            int start_i = t * chunk_size; //index startovy vrcholu i s kterym bude pracovat vlakno t
            int end_i = std::min((t + 1) * chunk_size, V); // koncovy index

            threads.emplace_back([&, start_i, end_i, k]() {
                for (int i = start_i; i < end_i; ++i) {
                    for (int j = 0; j < V; ++j) {
                        int dist_ik = distances[i][k];
                        int dist_kj = distances[k][j];
                        if (dist_ik < INF && dist_kj < INF) {
                            int new_dist = dist_ik + dist_kj;
                            if (new_dist < distances[i][j]) {
                                distances[i][j] = new_dist;
                                predecessors[i][j] = predecessors[k][j];
                            }
                        }
                    }
                }
            });
        }
        for (auto &th : threads) {
            th.join();
        }
    }
}



