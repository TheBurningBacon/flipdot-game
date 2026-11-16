//scene.cpp
#pragma once
#include <iostream>
#include "display.h"
#include "../text.h"

using namespace std;

//parrent class scene, each scene will be a different game.
class Scene {
private:
public:
    virtual void update(Display& screen,unordered_map<string,int> actions,string& scene) {
        
        if (actions["a"]) {
            write_text(screen,"TEST",0,0);
        }
    }
};

//Main menu scene, just makes the pixel 1,1 on when "b" is pressed
class MainMenu : public Scene {
public:
    void update(Display& screen,unordered_map<string,int> actions,string& scene) override {
        if (actions["b"]) {
            screen.set_pixel(1,1,true);
        }
    }
};