//
// Created by Octowhere on 12/3/2024.
//

#include "App.h"

#include <iostream>


App::App(const std::string& filename) : menu(graph) {
    std::cout << "Loading graph from file: " << filename << "\n";
    if(!graph.loadFromFile(filename)){
        std::cerr << "Error loading graph from file. Exiting.\n";
        exit(EXIT_FAILURE);
    }
    std::cout << "Graph successfully loaded.\n";
}

void App::run(){
    menu.run();
}