//
// Created by Octowhere on 12/3/2024.
//

#ifndef MENU_H
#define MENU_H
#include <memory>
#include <string>

#include "Graph.h"


class FloydWarshall;

class Menu {
private:
    Graph& graph;
public:
    Menu(Graph& graph);
    void run();
    void showMenu();
    void showHelp(const std::string& programName);

    void handleInvalidInput();
    void executeAlgorithm(const std::string &modeName, std::unique_ptr<FloydWarshall> fw);
    std::unique_ptr<FloydWarshall> initializeAlgorithm(int option);
};

#endif //MENU_H
