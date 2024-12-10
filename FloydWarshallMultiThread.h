//
// Created by Octowhere on 12/3/2024.
//

#ifndef FLOYDWARSHALLMULTITHREAD_H
#define FLOYDWARSHALLMULTITHREAD_H
#include <condition_variable>
#include <queue>
#include <thread>
#include <vector>

#include "FloydWarshall.h"


class Graph;

class FloydWarshallMultiThread : public FloydWarshall {
public:
    FloydWarshallMultiThread(const Graph &g, int num_threads);

    void compute() override;

private:
    int num_threads;
};



#endif //FLOYDWARSHALLMULTITHREAD_H
