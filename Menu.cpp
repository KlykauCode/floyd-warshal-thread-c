//
// Created by Octowhere on 12/3/2024.
//

#include "Menu.hpp"

#include <iostream>
#include <limits>
#include <memory>
#include <ostream>
#include <thread>

#include "FloydWarshallMultiThread.h"
#include "FloydWarshallSingleThread.h"

class FloydWarshall;
Menu::Menu(Graph &graph) : graph(graph) {};

void Menu::showMenu(){
    std::cout << "\n=== Floyd-Warshall Algorithm ===\n";
    std::cout << "1. Show help\n";
    std::cout << "2. Run single-threaded version\n";
    std::cout << "3. Run multi-threaded version\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option:  ";
}

void Menu::showHelp(const std::string& programName){
    std::cout << "\n=== Help ===\n";
    std::cout << "This project implements the Floyd-Warshall algorithm for finding the shortest paths between all pairs of vertices in a graph.\n\n";
    std::cout << "Menu options:\n";
    std::cout << "1 - Show this help.\n";
    std::cout << "2 - Run the single-threaded version of the algorithm.\n";
    std::cout << "3 - Run the multi-threaded version of the algorithm.\n";
    std::cout << "0 - Exit the program.\n";
}

void Menu::handleInvalidInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "Please enter a valid number.\n";
}

void Menu::executeAlgorithm(const std::string& modeName, std::unique_ptr<FloydWarshall> fw) {
    if (!fw) {
        std::cerr << "Failed to initialize the algorithm.\n";
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    fw->compute();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << modeName << " completed in " << duration << " ms.\n";

    if(graph.getNumVertices() < 15) {
        std::cout << "\n=== Initial Adjacency Matrix ===";
        std::cout << "\n";
        graph.printMatrix();

        fw->printDistances();

        std::cout << "\n=== Paths ===\n";
        int V = graph.getNumVertices();
        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j){
                if(i != j){
                    std::cout << "From " << i << " to " << j << ":\n";
                    std::cout << "Distance: ";
                    if(fw->getDistances()[i][j] == FloydWarshall::INF){
                        std::cout << "INF\n";
                    }
                    else{
                        std::cout << fw->getDistances()[i][j] << "\n";
                    }
                    std::cout << "Path: ";
                    fw->printPath(i, j);
                    std::cout << "\n";
                }
            }
        }
    }

}
std::unique_ptr<FloydWarshall> Menu::initializeAlgorithm(int option) {
    if (option == 2) {
        return std::make_unique<FloydWarshallSingleThread>(graph);
    } else if (option == 3) {
        return std::make_unique<FloydWarshallMultiThread>(graph, 4);
    }
    return nullptr;
}

void Menu::run() {
    while (true) {
        showMenu();
        int option;
        std::cin >> option;

        if (std::cin.fail()) {
            handleInvalidInput();
            continue;
        }
        if (option < 0 || option > 3) {
            std::cerr << "Please enter a number from 0 to 3.\n";
            continue;
        }
        switch (option) {
            case 1: {
                showHelp("FloydWarshall");
                break;
            }
            case 2:
            case 3: {
                std::string modeName = (option == 2) ? "Single-Threaded Version" : "Multi-Threaded Version";
                auto algorithm = initializeAlgorithm(option);
                executeAlgorithm(modeName, std::move(algorithm));
                break;
            }
            case 0: {
                std::cout << "Exiting the program.\n";
                return;
            }
        }
    }
}




