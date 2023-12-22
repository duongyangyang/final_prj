#pragma once
#include <iostream>
#include "Header.h"
#include <windows.h>
#include "Object.h"
using namespace std;

void box_move_horizontal(int x_start, int y_start, int x_end, string num){
    if (x_start >= x_end){
        for (int x = x_start; x >= x_end; x--){
            box(x,y_start,num);
            gotoXY(x+6,y_start); cout << " ";
            gotoXY(x+6,y_start+1); cout << " ";
            gotoXY(x+6,y_start+2); cout << " ";
            Sleep(20);
        }
    }

    else {
        for (int x = x_start; x <= x_end; x++){
            box(x,y_start,num);
            gotoXY(x-1,y_start); cout << " ";
            gotoXY(x-1,y_start+1); cout << " ";
            gotoXY(x-1,y_start+2); cout << " ";
            Sleep(20);            
        }
    }

}

void box_move_vertical(int x_start, int y_start, int y_end, string num){
    if (y_start >= y_end){
        for (int y = y_start; y >= y_end; y--){
            box(x_start,y,num);
            gotoXY(x_start,y+3); cout << "      ";
            Sleep(80);
        }
    }
    else{
        for (int y = y_start; y <= y_end; y++){
            gotoXY(x_start,y-1); cout << "      ";
            box(x_start,y,num);
            Sleep(80);           
        }        
    }

}

void cat_move_vertical(int x_start, int y_start, int y_end){
    if (y_start >= y_end){ 
        for (int y = y_start; y >= y_end; y--){
            cat(x_start,y);
            gotoXY(x_start,y+4); cout << "         ";
            gotoXY(x_start+7,y+2); cout << "  ";
            gotoXY(x_start+7,y+3); cout << "  ";
            Sleep(80);
        }
    }
    else {    
        for (int y = y_start+1; y <= y_end; y++){
            cat(x_start,y);
            gotoXY(x_start,y-1); cout << "         ";
            
            Sleep(80);
        }
    }
}


void cat_move_horizontal(int x_start, int y_start, int x_end){
    if (x_start >= x_end){
        for (int x = x_start; x >= x_end; x--){
            gotoXY(x+9,y_start); cout << " ";
            gotoXY(x+9,y_start+1); cout << " ";
            gotoXY(x+7,y_start+2); cout << " ";
            gotoXY(x+7,y_start+3); cout << " ";
            cat(x,y_start);
            Sleep(20);
        }
    }
    else{
            for (int x = x_start; x <= x_end; x++){
            gotoXY(x-1,y_start+1); cout << " ";
            cat(x,y_start);
            Sleep(20);
        }
    }
}

int game_level(int x, int y, int max_level){
    gotoXY(x,y); cout << "Choose game level: ";
    int level;
    gotoXY(x+19,y); ShowCur(true); cin >> level; ShowCur(false);
    int count = 1;
    while (level > max_level){
        gotoXY(x,y+count); cout << "You have not passed level " << max_level;
        gotoXY(x,y+count+1); cout <<"Please choose again!";
        gotoXY(x,y+count+2); cout << "Choose game level: ";
        gotoXY(x+19,y+count+2); cin >> level;
        count++;
    }
    return level;
}

void clear_animation(int x_root, int y_root){
        for (int i = x_root; i <= x_root+105; i++){
            for (int j = y_root; j <= y_root+30; j++){
                gotoXY(i,j); cout << " ";
            }
        }
}

void clear_animation_2(int level, int x_root, int y_root){
    for (int time = 0; time < 3; time ++){
        for (int p = y_root; p <= y_root+30; p++){
            gotoXY(x_root,p); 
            cout << "LEVEL " << level << " " << "LEVEL " << level << " " << "LEVEL " 
            << level << " " << "LEVEL " << level << " " << "LEVEL " << level << " " 
            << "LEVEL " << level << " " << "LEVEL " << level << " " << "LEVEL " << level 
            << " " << "LEVEL " << level << " " << "LEVEL " << level << " " << "LEVEL " 
            << level << " " << "LEVEL " << level << " " << "LEVEL " << level << " ";
            if(p%15!=0&&p%15!=8){
               SetColor(p%15); 
            } else {SetColor(8);}
            
            Sleep(30 - time*4);
        }
        for (int i = x_root; i <= x_root+105; i++){
            for (int j = y_root; j <= y_root+30; j++){
                gotoXY(i,j); cout << " ";
            }
        }

    }
    SetColor(15);
}