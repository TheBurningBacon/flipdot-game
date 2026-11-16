//display.h
#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Class that saves the grid state and is updated rather than the screen
//This way we can seperate the game and the actual screen 
class Display {
private:
  int size_x;
  int size_y;
  vector<vector<bool>> grid;//list of collumns(also a list) of bools
public:
  Display(int size_x,int size_y) : size_x(size_x), size_y(size_y) {


    //initializes the grid to all false
    //false == dark side
    //true == brid side
    for (int x=0;x<size_x;x++) {
      vector<bool> collumn;
      for (int y=0;y<size_y;y++) {
        collumn.push_back(false);
      }
      grid.push_back(collumn);
    }
  }


  void set_pixel(int x,int y,bool state) {
    grid[x][y]=state;
  }

  void flip_pixel(int x,int y) {
    grid[x][y]=!grid[x][y];
  }

  bool get_pixel(int x,int y) {
    return grid[x][y];
  }

  void place_shape(int pos_x,int pos_y,vector<vector<int>> shape) {
    //in shape:
    /*0=dark
    1=bright
    2=flip
    -1=no change
    */
    if (!shape.empty()) {
      for (size_t x=0;x<shape.size();x++) {
        for (size_t y=0;y<shape[0].size();y++) {
          if (shape[x][y]==1 || shape[x][y]==0) {
            set_pixel(pos_x+x,pos_y+y,shape[x][y]);
          }
          else if (shape[x][y]==2) {
            flip_pixel(pos_x+x,pos_y+y);
          }
        }
      }
    }
  }

  void print(bool grid_lines=false) {
    //swap the x and y for printing becuase it's printing in rows not collumns
    for (int y=0;y<size_y;y++) {
      for (int x=0;x<size_x;x++) {
        if (grid[x][y]) {
          cout << "#";
        }
        else {
          cout << " ";
        }
        if (grid_lines) {
          cout << "|";
        }
      }
      //end of x-loop
      cout << endl;
    }
    //end of y-loop
  }
};

