//scene.cpp
#pragma once
#include <iostream>
#include "display.h"
#include "../text.h"

using namespace std;

//parrent class scene, each scene will be a different game.
class Scene {
private:
    int frame_count=-1;//used for animations
    vector<tuple<int,int,int,vector<vector<int>>,int,int>> animations;
    //start_frame,end_frame,loop_interval,shape,x,y
public:
    Scene() {}
    int tick(Display& screen) {
        frame_count++;

        for (auto a:animations) {
            if ((frame_count-get<0>(a))%get<2>(a)==0) {
                screen.place_shape(get<4>(a),get<5>(a),get<3>(a));
            }
        }
        size_t i = 0;
        while (i < animations.size()) {
            if (get<1>(animations[i])!=-1 && get<1>(animations[i])<frame_count) {
                animations[i] = std::move(animations.back());
                animations.pop_back();
            } else {
                ++i;
            }
        }

        
        return frame_count;
    }
    void add_animation(int start_frame,int end_frame,int loop_interval,vector<vector<int>> shape,int x,int y) {
        animations.push_back({start_frame,end_frame,loop_interval,shape,x,y});
    }
    virtual void enter_scene(Display& screen) {
        cout << "test";
    }
    virtual void update(Display& screen,unordered_map<string,int> actions,string& scene) {
        
        if (actions["a"]) {
            write_text(screen,"TEST",0,0);
        }
    }
    
};

//Main menu scene, just makes the pixel 1,1 on when "b" is pressed
class MainMenu : public Scene {
public:
    void enter_scene(Display& screen) override {
        write_text(screen,"A",7,4);
        add_animation(0,-1,10,{{2,2,2,2,2,2},{2,2,2,2,2,2},{2,2,2,2,2,2},{2,2,2,2,2,2},{2,2,2,2,2,2}},6,3);
    }
    void update(Display& screen,unordered_map<string,int> actions,string& scene) override {
        int frame=tick(screen);
        cout << frame;

        

        if (actions["b"]) {
            screen.set_pixel(1,1,true);
        }
    }
};