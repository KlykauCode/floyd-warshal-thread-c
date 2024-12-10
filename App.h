//
// Created by Octowhere on 12/3/2024.
//

#ifndef APP_H
#define APP_H
#include "Menu.hpp"


class App {
private:
    Graph graph;
    Menu menu;
public:
    App(const std::string& filename);
    void run();
};



#endif //APP_H
