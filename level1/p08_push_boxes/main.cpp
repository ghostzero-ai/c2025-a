#include<bits/stdc++.h>
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//宏定义
#define KEY_UP(VK_UP) ((GetAsyncKeyState(VK_UP) & 0x8000) ? 1 : 0)
#define KEY_DOWN(VK_DOWN) ((GetAsyncKeyState(VK_DOWN) & 0x8000) ? 1 : 0)
#define KEY_LEFT(VK_LEFT) ((GetAsyncKeyState(VK_LEFT) & 0x8000) ? 1 : 0)
#define KEY_RIGHT(VK_RIGHT) ((GetAsyncKeyState(VK_RIGHT) & 0x8000) ? 1 : 0)
#define WALL '*'
#define GAMEPLAYER '!'
#define EXIT 'E'
#define PATH ' '
#define BOX '#'
#define MAX 6//关数

struct move_thing {
    int x;
    int y;
};

//函数原型
void read(vector<string> *map,string filename,int *length_x,int *length_y);
void move_person(vector<string> *map,int t,int *flag,move_thing *person,int length_x,int length_y,vector<vector<int>> *map_exit);
int move_box(vector<string> *map,int t,int *flag,int length_x,int length_y,int x,int y,vector<vector<int>> *map_exit);
void show(int length_x,int length_y,vector<string> *map);

//读入地图
void read(vector<string> *map,string filename,int *length_x,int *length_y) {
    ifstream file(filename);
    if(!file.is_open()) {
        cerr<<"File Not Found"<<endl;
        exit(1);
    }
    //按行读入
    string line;
    while(getline(file,line)) {
        map->push_back(line);
        (*length_y)++;
        (*length_x)=line.length();

    }
}

void move_person(vector<string> *map,int t,int *flag,move_thing *person,int length_x,int length_y,vector<vector<int>> *map_exit) {
    //移动方向检测
    int move_forward[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    //判断是否可走&&判断是否是箱子+操控主角行动
    if (person->y+move_forward[t][0]>=0&&person->y+move_forward[t][0]<length_y&&person->x+move_forward[t][1]>=0&&person->x+move_forward[t][1]<length_x) {
        if ((*map)[person->y+move_forward[t][0]][person->x+move_forward[t][1]]==PATH||(*map)[person->y+move_forward[t][0]][person->x+move_forward[t][1]]==EXIT) {
            (*map)[person->y+move_forward[t][0]][person->x+move_forward[t][1]]=GAMEPLAYER;
            (*map)[person->y][person->x]=PATH;
            if ((*map_exit)[person->y][person->x]==1) {
                (*map)[person->y][person->x]=EXIT;
            }
            person->x+=move_forward[t][1];
            person->y+=move_forward[t][0];
        }else if ((*map)[person->y+move_forward[t][0]][person->x+move_forward[t][1]]==BOX) {//检测到有箱子，判断箱子能不能动并控制其移动
            if (move_box(map, t, flag, length_x, length_y,person->x+move_forward[t][1],person->y+move_forward[t][0],map_exit)) {//根据箱子能不能走判断人能不能走
                (*map)[person->y+move_forward[t][0]][person->x+move_forward[t][1]]=GAMEPLAYER;
                (*map)[person->y][person->x]=PATH;
                if ((*map_exit)[person->y][person->x]==1) {
                    (*map)[person->y][person->x]=EXIT;
                }
                person->x+=move_forward[t][1];
                person->y+=move_forward[t][0];
            }
        }


    }


}

//箱子移动
int move_box(vector<string> *map, int t, int *flag, int length_x, int length_y,int x,int y,vector<vector<int>> *map_exit) {
    int move_forward[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    if (y+move_forward[t][0]>=0&&y+move_forward[t][0]<length_y&&x+move_forward[t][1]>=0&&x+move_forward[t][1]<length_x) {
        if ((*map)[y+move_forward[t][0]][x+move_forward[t][1]]==EXIT) {//进入终点得分
            (*map)[y+move_forward[t][0]][x+move_forward[t][1]]=BOX;
            (*map)[y][x]=PATH;

            (*flag)++;
            if ((*map_exit)[y][x]==1) {//出终点扣分并还原终点
                (*map)[y][x]=EXIT;
                (*flag)--;

            }

            return 1;
        }else if ((*map)[y+move_forward[t][0]][x+move_forward[t][1]]==PATH) {
            (*map)[y+move_forward[t][0]][x+move_forward[t][1]]=BOX;
            (*map)[y][x]=PATH;
            if ((*map_exit)[y][x]==1) {//出终点扣分并还原终点
                (*map)[y][x]=EXIT;
                (*flag)--;

            }

            return 1;
        }
    }
    return 0;
}

//打印地图
void show(int length_x,int length_y,vector<string> *map) {

    system("cls");

    for (int i=0;i<length_y;i++) {
        for (int j=0;j<length_x;j++) {
            cout<<(*map)[i][j]<<"  ";

        }
        cout<<endl;

    }

}


int main() {
    cout<<WALL<<"为墙，"<<GAMEPLAYER<<"为玩家，"<<EXIT<<"为箱子的终点，"<<BOX<<"为箱子\n";
    cout<<"游戏共有"<<MAX<<"关，请问要从第几关开始\n";
    int n;
    cin>>n;

    //防止输入错误
    while (n>MAX||n<1) {
        system("cls");
        cout<<"无此关，请重新输入";
        cin>>n;
    }

    //从第n关开始到最后
    for(int i=n;i<=MAX;i++) {
        cout<<"现在是第"<<i<<"关"<<endl;
        Sleep(500);

        int flag=0;
        int flag_max=0;
        int length_x=0;
        int length_y=0;
        move_thing person;
        string filename;
        vector<string> map;
        vector<vector<int>> map_exit;
        //读入地图
        switch (i) {
            case 1:
                read(&map,"map1.txt",&length_x,&length_y);
                break;
            case 2:
                read(&map,"map2.txt",&length_x,&length_y);
                break;
            case 3:
                read(&map,"map3.txt",&length_x,&length_y);
                break;
            case 4:
                read(&map,"map4.txt",&length_x,&length_y);
                break;
            case 5:
                read(&map,"map5.txt",&length_x,&length_y);
                break;
            case 6:
                read(&map,"map6.txt",&length_x,&length_y);
                break;
            default:
                cerr<<"error"<<endl;
        }
        //检测主角位置和箱子个数
        for(int j=0;j<length_y;j++) {
            vector<int> row;
            for(int k=0;k<length_x;k++) {
                if (map[j][k]==GAMEPLAYER) {
                    person.x=k;
                    person.y=j;
                }
                if (map[j][k]==EXIT) {
                    row.push_back(1);
                    flag_max++;
                }else {
                    row.push_back(0);
                }

            }
            map_exit.push_back(row);
        }


        system("cls");
        show(length_x,length_y,&map);

        //检测移动直到结束
        while(1) {

            if (flag==flag_max) {
                system("cls");
                cout<<"You are Winner";
                Sleep(1000);
                system("cls");
                break;
            }
            if (KEY_UP(VK_UP)){


                move_person(&map,0,&flag,&person,length_x,length_y,&map_exit);
                show(length_x,length_y,&map);

                Sleep(200);
            }

            if (KEY_DOWN(VK_DOWN)){


                move_person(&map,1,&flag,&person,length_x,length_y,&map_exit);
                show(length_x,length_y,&map);
                Sleep(200);
            }

            if (KEY_LEFT(VK_LEFT)){

                move_person(&map,2,&flag,&person,length_x,length_y,&map_exit);
                show(length_x,length_y,&map);
                Sleep(200);
            }

            if (KEY_RIGHT(VK_RIGHT)){

                move_person(&map,3,&flag,&person,length_x,length_y,&map_exit);
                show(length_x,length_y,&map);

                Sleep(200);
            }



        }
    }
    cout<<"You win all gamess";
    Sleep(1000);
    return 0;
}
