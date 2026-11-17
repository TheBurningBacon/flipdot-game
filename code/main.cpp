//main.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "classes/scene.h"
#include "classes/display.h"

using namespace std;

void debug_inputs(unordered_map<string,int>& actions) {
  string input;
  cin >> input;
  
  string val;
  string typ;
  bool in_val = false;
  for (char c:input) {
    if (c==',') {
      actions[typ]=stoi(val);
      val="";
      typ="";
      in_val=false;
    }
    else if (c==':') {
      in_val=true;
    }
    else if (in_val) {
      val+=c;
    }
    else {
      typ+=c;
    }
  }

}



extern "C" void app_main(void) {


  //init
  bool power_on=true;
  Display screen(16,9);
  unordered_map<string,int> actions ={
    {"a",0}, //either 0 or 1
    {"b",0},
    {"c",0},
    {"d",0},
    {"start",0},
    {"quit",0},
    {"left_stick_x",0}, //range -1 to 1
    {"left_stick_y",0},
    {"right_stick_x",0},
    {"right_stick_y",0},
  };



  unordered_map<string,unique_ptr<Scene>> scenes;
  scenes["main"]=make_unique<MainMenu>();
  scenes["test"]=make_unique<Scene>();
  string scene="main";
  
  //call for the first scene to initialize
  scenes[scene]->enter_scene(screen);
  //main loop
  while (power_on) {
    scenes[scene]->update(screen,actions,scene);
    
    //vTaskDelay(pdMS_TO_TICKS(1000));
    screen.print(true);
    debug_inputs(actions);
  }
  
}


int main() {
  app_main();
  return 0;
}