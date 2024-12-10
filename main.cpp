#include <iostream>

#include "App.h"
#include "FloydWarshall.h"
#include "Menu.hpp"

int main(int argc, char* argv[]) {
    std::string filename = "graph1.txt";

    App app(filename);
    app.run();
    return 0;
}
