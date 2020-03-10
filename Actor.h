//
// Created by ilya on 10.03.2020.
//

#ifndef RENDER_ACTOR_H
#define RENDER_ACTOR_H

#include <string>
#include "Settings.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Actor {
public:
    Actor(Settings *settings);

    int prepare();

    int start();

    int stop();

private:
    Settings *settings;
    pid_t pid;
    string cmd;

    int system();

    void thread_function();
};


#endif //RENDER_ACTOR_H
