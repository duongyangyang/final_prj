#pragma once
#include <iostream>
#include "Header.h"
using namespace std;

void wall(int x_root_wall, int y_root_wall){
    int x_on = x_root_wall; int y_on = y_root_wall;
    while (x_on <= x_root_wall+100){
        gotoXY(x_on,y_on);
        cout << "+";
        x_on++;
    }
    int x_down = x_root_wall; int y_down = y_root_wall+30;
    while (x_down <= x_root_wall+100) {
        gotoXY(x_down,y_down);
        cout << "+";
        x_down++;
    }  
    int x_left = x_root_wall; int y_left = y_root_wall;
    while (y_left <= y_root_wall+30){
        gotoXY(x_left,y_left);
        cout << "+";
        y_left++;
    }
    int x_right = x_root_wall+100; int y_right = y_root_wall;
    while (y_right <= y_root_wall+30){
        gotoXY(x_right,y_right);
        cout << "+";
        y_right++;
    }
}
void wall_ver_middle(int x_root_wall, int y_root_wall){
    int x_ver_middle = x_root_wall+65; int y_ver_middle = y_root_wall;
    while (y_ver_middle <= y_root_wall+30){
        gotoXY(x_ver_middle,y_ver_middle);
        cout << "+";
        y_ver_middle++;
    }
}
void wall_hor_middle (int x_root_wall, int y_root_wall){
    int x_hor_middle = x_root_wall; int y_hor_middle = y_root_wall+2;
    while (x_hor_middle <= x_root_wall+100) {
        gotoXY(x_hor_middle,y_hor_middle);
        cout << "+";
        x_hor_middle++;
    } 
}
void wall_hor_middle_2 (int x_root_wall, int y_root_wall){
    int x_hor_middle = x_root_wall; int y_hor_middle = y_root_wall+28;
    while (x_hor_middle <= x_root_wall+100) {
        gotoXY(x_hor_middle,y_hor_middle);
        cout << "+";
        x_hor_middle++;
    } 
    gotoXY(x_root_wall+65, y_root_wall+29); cout << " ";
}

void small_hor_line (int x_root_wall, int y_root_wall){
    int x_hor_middle = x_root_wall+65; int y_hor_middle = y_root_wall+20;
    while (x_hor_middle <= x_root_wall+100) {
        gotoXY(x_hor_middle,y_hor_middle);
        cout << "+";
        x_hor_middle++;
    } 
}

void outbox_line(int x_box_out, int y_box_out, int y_root){
    while (y_box_out <= y_root+25) {
        gotoXY(x_box_out-1,y_box_out);
        cout << "|      |";
        y_box_out++;
    } 

} 

void box(int x_box, int y_box, string num){
    gotoXY(x_box,y_box);
    cout << "+----+";
    gotoXY(x_box,y_box + 1);
    cout << "| " << num << " |";
    gotoXY(x_box,y_box + 2);
    cout << "+----+";
}

void cat(int x, int y){
    gotoXY(x,y); cout << "    _____";
    gotoXY(x,y+1); cout << "\\___|O.O|";
    gotoXY(x,y+2); cout << " | __ |";
    gotoXY(x,y+3); cout << " ||  ||";
}

void null_box(int null[], int numofbox){
    int y_box_distance = 3;
    int x_box_in = 14; int y_box_in = 10; int i = 0;
    string temp;
    for(int i = 0; i < numofbox; i++){
        temp = to_string(null[i]);
        if (i < 4){
            box(x_box_in +7*(i+2), y_box_in + 11, "NA");
            gotoXY(x_box_in +7*(i+2), y_box_in + 14);
            cout << "N."<<i+1;
        }
        else{
            box(x_box_in +7*(i-4+2), y_box_in + 15, "NA");
            gotoXY(x_box_in +7*(i-4+2), y_box_in + 18);
            cout << "No."<<i+1;
        }
    }
}

void input_box(vector<string> inp_num){
    int y_box_distance = 3;
    int x_box_in = 14; int y_box_in = 10;
    box(x_box_in, y_box_in, inp_num.at(0));
    box(x_box_in, y_box_in + y_box_distance, inp_num.at(1));
    box(x_box_in, y_box_in + 2*y_box_distance, inp_num.at(2));
    box(x_box_in, y_box_in + 3*y_box_distance, inp_num.at(3));
    box(x_box_in, y_box_in + 4*y_box_distance, inp_num.at(4));
    box(x_box_in, y_box_in + 5*y_box_distance, inp_num.at(5));
}


