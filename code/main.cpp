//main.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "classes/scene.h"
#include "classes/display.h"

using namespace std;




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


  MainMenu main_menu;
  Scene test;
  string scene="test";
  

  //main loop
  while (power_on) {
    if (scene=="test") {
      test.update(screen,actions,scene);
    }
    if (scene=="main") {
      main_menu.update(screen,actions,scene);
    }
    
    //vTaskDelay(pdMS_TO_TICKS(1000));
    screen.print(true);
  }
  
}
