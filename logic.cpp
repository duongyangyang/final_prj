#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string.h>
#include "Header.h"
#include "Object.h"
#include "Command.h"
#include "Animation.h"
using namespace std;
int x_root = 10; int y_root = 1; int end_key = 0;
void startScreen(int x_root, int y_root);
int levelScreen(int level, int x_root, int y_root);
void ingameScreen(int x_root, int y_root);
vector<string> create_input_array_str(vector<int> input_array);
string inttostr_add0(int a);

bool whether_int(string a){
    try{
        int p = stoi(a);
        double q = stod(a);
        if(p-q == 0){
            return true;
        }else{return false;}
    }catch(invalid_argument&){
        return false;
    }

}


void ninenine_for_all(int list[], int size){
    for (int i = 0; i < size; i++){
        list[i] = -99;
    }
}

int main(){
    //Take level
    int max_level; 
    ifstream Level ("level.txt");
    if(Level.fail()){
        cout << "No required data, game has been automatically reset!" << endl;
        ofstream Level ("level.txt");
        Level << "1";
        max_level = 1;
    }
    else{
        while (!Level.eof()){
            Level >> max_level;
        }
    }
    
    //Start
    ShowCur(false);
    resizeConsole(1000, 600);
    SetConsoleTitle("THE CATTY's WORLD");
    system("cls");
    while (end_key != 112)
    {
        startScreen(x_root,y_root);
        end_key = inputKey();
    }
    clear_animation(x_root, y_root); Sleep(100);
    int level = levelScreen(max_level, x_root, y_root);
    clear_animation(x_root, y_root);

    int com_num = 100; int temp_arr_num; int end_point;

    //Variables for data
    vector<int> inp_arr;
    vector<string> inp_arr_str;
    vector<int> out_arr;
    vector<int> result;
    //Data
    if(level == 1){
        inp_arr = {1,2};
        inp_arr_str = create_input_array_str(inp_arr);
        result = {1,2};
        end_point = 2;
        temp_arr_num = 0;
    }
    else if(level == 2){
        inp_arr = {3,9,5,1,-2,-2,9,-9};
        inp_arr_str = create_input_array_str(inp_arr);
        result = {-6,6,4,-4,0,0,18,-18};
        end_point = 8;
        temp_arr_num = 3; 
    }
    else if(level == 3){
        inp_arr = {6,2,7,7,-9,3,-3,-3};
        inp_arr_str = create_input_array_str(inp_arr);
        result = {7,-3};
        end_point = 2;
        temp_arr_num = 3;
    }
    else if(level == 4){
        inp_arr = {4,7,0,-2,4,0,9,0,0};
        inp_arr_str = create_input_array_str(inp_arr);
        result = {0,0,0,0};
        end_point = 4;
        temp_arr_num = 0;
    }
    else{return 0;}
    int temp_arr[temp_arr_num]; ninenine_for_all(temp_arr, temp_arr_num);

    input_box(inp_arr_str);
    ingameScreen(x_root,y_root);
    gotoXY(x_root+29,y_root+1); cout << "LEVEL " << level; 
    null_box(temp_arr, temp_arr_num);
    //Get command list
    vector<string> command_str; int command_int[com_num];
    ninenine_for_all(command_int,com_num);
    for(int i = 0; i < com_num; i++){
        string command; 
        ShowCur(true); 
        gotoXY(x_root+70,y_root+7+i); printf("%02d. ", i+1);
        gotoXY(x_root+74,y_root+7+i); cin >> command; 
        ShowCur(false);
        command_str.push_back(command);
        if(command == "done"){
            break;
        }
        else if(command == "inbox" || command == "outbox"){
            continue;
        }
        else if((command == "jump" || command == "jumpifzero") && level != 1){ //第一关卡不能用
            try
            {
                string num_temp_str; cin >> num_temp_str;
                if(!whether_int(num_temp_str)){
                    gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                    gotoXY(0,32);
                    return 0;                    
                }
                int num_temp_i = stoi(num_temp_str); //利用stoi处理大部分输入问题
                if(num_temp_i > com_num || num_temp_i < 1){ //jump——jumpifzero的参数要求
                    gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                    gotoXY(0,32);
                    return 0;
                }
                else{command_int[i] = num_temp_i;}
            }
            catch(invalid_argument&) //输入有问题
            {
                gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                gotoXY(0,32);
                return 0;
            }
            
        }
        else if((command == "add" || command == "sub") && level != 1){
            try
            {
                string num_temp_str; cin >> num_temp_str;
                if(!whether_int(num_temp_str)){
                    gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                    gotoXY(0,32);
                    return 0;                    
                }
                int num_temp_i = stoi(num_temp_str);
                if(num_temp_i > temp_arr_num || num_temp_i < 0){ //Loại bỏ lỗi quá giới hạn mảng
                    gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                    gotoXY(0,32);
                    return 0;
                } else{command_int[i] = num_temp_i;}
            }
            catch(invalid_argument&) //Loại bỏ lỗi nhập ngu
            {
                gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                gotoXY(0,32);
                return 0;
            }
        }
        else if((command == "copyto" || command == "copyfrom") && level != 1){
            try
            {
                string num_temp_str; cin >> num_temp_str;
                if(!whether_int(num_temp_str)){
                    gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                    gotoXY(0,32);
                    return 0;                    
                }
                int num_temp_i = stoi(num_temp_str);
                if(num_temp_i > temp_arr_num || num_temp_i <= 0){ //Ô trống không tồn tại
                    gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                    gotoXY(0,32);
                    return 0;
                }else{
                    command_int[i] = num_temp_i;
                }
            }
            catch(invalid_argument&)
            {
                gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect syntax in line " << i+1 << endl;
                gotoXY(0,32);
                return 0;
            }
        }
        else {
            gotoXY(x_root+21,y_root+29); cout << "LINE " << i+1 << " HAS UNDEFINED COMMAND!!";
            gotoXY(0,32);
            return 0;
        }

    }

    //logic
    int count = 0; int in_process = -99; 
    while(end_point > 0){
        gotoXY(x_root+68, y_root+7+count); cout << ">";
        try{string a = command_str.at(count);}
        catch(out_of_range&){
                gotoXY(x_root+21,y_root+29); cout << "Error! - Incorrect within JUMP(IFZERO) syntax" << endl;
                gotoXY(0,32);
                return 0;
        }
        //INBOX
        if(command_str.at(count) == "inbox"){
            in_process = inp_arr.at(0);
            if((inttostr_add0(in_process)).size() > 5){
                gotoXY(x_root+21,y_root+29); cout << "Error! - No more box" << endl;
                gotoXY(0,32);
                return 0;
            }
            inbox(inttostr_add0(in_process));
            for(int i = 0; i < inp_arr.size(); i++){
                inp_arr[i] = inp_arr[i+1];
            }
            inp_arr_str = create_input_array_str(inp_arr);
            input_box(inp_arr_str);
        }
        //OUTBOX
        else if(command_str.at(count) == "outbox"){
            if(in_process == -99){ //Không có khối gỗ trên tay
                gotoXY(x_root+21,y_root+29); cout << "Error! - OUTBOX command has incorrect syntax" << endl;
                gotoXY(0,32);
                return 0;
            }
            else{
                outbox(inttostr_add0(in_process));
                out_arr.push_back(in_process);
                in_process = -99;
                end_point = end_point - 1 ;
            }
        }
        //ADD
        else if(command_str.at(count) == "add"){
            int num = command_int[count];
            if(in_process == -99 || temp_arr[num] == -99){ //Không có khối gỗ trên tay hoặc không có gỗ ở ô trống
                gotoXY(x_root+21,y_root+29); cout << "Error! - ADD command has incorrect syntax" << endl;
                gotoXY(0,32);
                return 0;
            }
            else{
                int temp = in_process;
                in_process = in_process + temp_arr[num];
                add_sub(num,inttostr_add0(temp_arr[num]),inttostr_add0(temp), inttostr_add0(in_process));
            }            
            
        }
        //SUB
        else if(command_str.at(count) == "sub"){
            int num = command_int[count];
            if(in_process == -99 || temp_arr[num] == -99){ //Không có khối gỗ trên tay hoặc không có gỗ ở ô trống
                gotoXY(x_root+21,y_root+29); cout << "Error! - SUB command has incorrect syntax" << endl;
                gotoXY(0,32);
                return 0;
            }
            else{
                int temp = in_process;
                in_process = in_process - temp_arr[num];
                add_sub(num,inttostr_add0(temp_arr[num]),inttostr_add0(temp),inttostr_add0(in_process));
                
            }
        }
        //COPYTO
        else if(command_str.at(count) == "copyto"){
            int num = command_int[count];
            if(in_process == -99){ //Không có khối gỗ trên tay
                gotoXY(x_root+21,y_root+29); cout << "Error! - COPYTO command has incorrect syntax" << endl;
                gotoXY(0,32);
                return 0;
            }
            else{
                temp_arr[num] = in_process;
                copyto(num, inttostr_add0(in_process));
                in_process = -99;
            }            
        }

        //COPYFROM
        else if(command_str.at(count) == "copyfrom"){
            int num = command_int[count];
            if(temp_arr[num] == -99){ //Không có khối gỗ trên tay
                gotoXY(x_root+21,y_root+29); cout << "Error! - COPYFROM command has incorrect syntax" << endl;
                gotoXY(0,32);
                return 0;
            }
            else{
                in_process = temp_arr[num];
                copyfrom(num, inttostr_add0(in_process));
            }            
        }
        //JUMP
        else if (command_str.at(count) == "jump"){
            int num = command_int[count];
            Sleep(500);
            gotoXY(x_root+68, y_root+7+count); cout << " ";
            count = num - 1;
            continue;
        }

        //JUMPif0
        else if (command_str.at(count) == "jumpifzero"){
            if(in_process == -99){ //Không có khối gỗ trên tay
                gotoXY(x_root+21,y_root+29); cout << "Error! - JUMPIFZERO command has incorrect syntax" << endl;
                gotoXY(0,32);
                return 0;
            }
            else if(in_process == 0){
                int num = command_int[count];
                Sleep(500);
                gotoXY(x_root+68, y_root+7+count); cout << " ";
                count = num - 1;
                continue;
            }
        }
        else if (command_str.at(count) == "done"){break;}
        gotoXY(x_root+68, y_root+7+count); cout << " ";
        
        count++;
    }

    //Check result
    try{
        int res = 0;
        for(int i = 0; i < result.size(); i++){
            if(result.at(i) == out_arr.at(i)){
                res++;
                }
        }
        if(res == result.size()){
            if(level == max_level){ //自动升级关卡
                ofstream Level ("level.txt",ios::app);
                Level << " " << level + 1;
            }
            gotoXY(x_root+21,y_root+29); cout << "Success! Press P to continue, Q to quit"; 
        } else{gotoXY(x_root+21,y_root+29); cout << "Fail! Press P to continue, Q to quit";}
    } catch(out_of_range&){
        gotoXY(x_root+21,y_root+29); cout << "Fail! Press P to continue, Q to quit";
    }
    
    while(true){
        int key = inputKey();
        if(key == 112){
            main();
            break;
        }
        if(key == 113){
            break;}
    }
    gotoXY(0,32);
    SetColor(15);
    
    return 0;
}

void startScreen(int x_root, int y_root){
    wall(x_root, y_root);
    gotoXY(x_root+35,y_root+12); SetColor(2); cout << "WELCOME TO THE CATTY's WORLD!"; Sleep(100);
    gotoXY(x_root+35,y_root+13); SetColor(6); cout << "WELCOME TO THE CATTY's WORLD!"; Sleep(100);
    gotoXY(x_root+35,y_root+14); SetColor(9); cout << "WELCOME TO THE CATTY's WORLD!"; Sleep(100);
    SetColor(15);
    gotoXY(x_root+40,y_root+27); cout << "PRESS P TO CONTINUE"; Sleep(300);
    gotoXY(x_root+40,y_root+27); cout << "                   "; Sleep(300);
    SetColor(15);
}

int levelScreen(int level, int x_root, int y_root){
    wall(x_root, y_root);
    wall_hor_middle(x_root, y_root);
    wall_ver_middle(x_root, y_root);
    gotoXY(x_root+70,y_root+1);
    cout << "========== CODE ==========";
    int picked_level = game_level(x_root+70,y_root+6,level);
    clear_animation_2(picked_level, x_root, y_root);
    return picked_level;
}

void ingameScreen(int x_root, int y_root){
    wall(x_root, y_root);
    wall_hor_middle(x_root, y_root);
    wall_ver_middle(x_root, y_root);
    wall_hor_middle_2(x_root, y_root);
    small_hor_line(x_root,y_root);
    outbox_line(66,15,y_root);
    cat(40,13);
    gotoXY(x_root+3,y_root+29); cout << "System's message:";
    gotoXY(x_root+70,y_root+1); cout << "========== CODE ==========";
    gotoXY(x_root+70,y_root+6); cout << "It's work timeeee: ";
}

vector<string> create_input_array_str(vector<int> input_array){
    vector<string> input_array_str;
    for (int i = 0; i < input_array.size(); i++){
        string temp = to_string(input_array.at(i));
        if (temp.size() == 2){
            input_array_str.push_back(temp);
        }
        else if (temp.size() == 1){
            temp = "0" + temp;
            input_array_str.push_back(temp);
        }
    }
    if (input_array.size() < 16){
        for (int i = 0; i < 16 - input_array_str.size(); i++){
            input_array_str.push_back("NA");
        }
    }
    return input_array_str;
}

string inttostr_add0(int a){
    string b = to_string(a);
    if (b.size() == 1){
        return "0" + b;
    }
    else{
        return b;
    }
}