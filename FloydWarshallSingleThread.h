//
// Created by Octowhere on 12/3/2024.
//

#ifndef FLOYDWARSHALLSINGLETHREAD_H
#define FLOYDWARSHALLSINGLETHREAD_H
#include "FloydWarshall.h"


class Graph;

class FloydWarshallSingleThread : public FloydWarshall {
public:
    FloydWarshallSingleThread(const Graph& g);
    void compute() override;
};



#endif //FLOYDWARSHALLSINGLETHREAD_H
