#pragma once
#include <iostream>
#include "Object.h"
#include "Header.h"
#include "Animation.h"

void inbox(string box){
    cat_move_horizontal(40,13,21);
    box_move_horizontal(14,10,24,box);
    for (int i = 22; i<=40; i++){
        cat_move_horizontal(i-1,13,i);
        box_move_horizontal(i+2,10,i+3,box);
    }
}

void outbox(string box){
    for (int i = 41; i<=55; i++){
        cat_move_horizontal(i-1,13,i);
        box_move_horizontal(i+2,10,i+3,box);
    }        
    box_move_horizontal(58,10,66,box);
    cat_move_horizontal(55,13,40);
    box_move_vertical(66,10,25,box);
    gotoXY(66,25); cout << "      ";
    gotoXY(66,25+1); cout << "      ";
    gotoXY(66,25+2); cout << "      ";
    Sleep(700);
    }

void copyto(int x, string box_num){
    for (int i = 10; i < 14; i++){
        cat_move_vertical(40,i+3,i+4);
        box_move_vertical(43,i,i+1,box_num);
    }
    for(int i = 4; i < 7; i++){
        SetColor(i);
        box(14 +7*(x+1), 21, box_num);
        Sleep(1000);
    }
    SetColor(15);
    box(14 +7*(x+1), 21, box_num);
    cat_move_vertical(40,16,13); 
    Sleep(700);
}

void copyfrom(int x, string box_num){
    cat_move_vertical(40,13,16);
    for(int i = 4; i < 7; i++){
        SetColor(i);
        box(14 +7*(x+1), 21, box_num);
        Sleep(1000);
    }
    SetColor(15);
    box_move_vertical(43,12,10,box_num);
    cat_move_vertical(40,16,13); 
    box(14 +7*(x+1), 21, box_num);
    Sleep(700);
}

void add_sub(int x, string box_num_old, string in_process, string box_num_new){
    for (int i = 10; i < 14; i++){
        cat_move_vertical(40,i+3,i+4);
        box_move_vertical(43,i,i+1,in_process);
    }
    for(int i = 4; i < 7; i++){
        SetColor(i);
        box(14 +7*(x+1), 21, box_num_old);
        Sleep(1000);
    }
    SetColor(15);
    box(14 +7*(x+1), 21, box_num_old);
    box_move_vertical(43,12,10,box_num_new);
    cat_move_vertical(40,16,13); 
    Sleep(700);
}
