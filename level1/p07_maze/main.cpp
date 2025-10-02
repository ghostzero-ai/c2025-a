#include<bits/stdc++.h>
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define KEY_DOWN(VK_UP) ((GetAsyncKeyState(VK_UP) & 0x8000) ? 1 : 0)
#define KEY_DOWN(VK_DOWN) (GetAsyncKeyState(VK_DOWN) & 0x8000 ? 1 : 0)
#define KEY_DOWN(VK_LEFT)((GetAsyncKeyState(VK_LEFT) & 0x8000) ? 1 : 0)
#define KEY_DOWN(VK_RIGHT)((GetAsyncKeyState(VK_RIGHT) & 0x8000) ? 1 : 0)
#define WALL '#'
#define GAMEPLAYER '!'
#define EXIT 'E'
#define PATH '0'
#define LONG 10//方形地图长度(只能为偶数)

//函数原型
void cpsma();
void sxmap();//刷新屏幕
void UP();
void DOWN();
void LEFT();
void RIGHT();
void create_map(int x,int y);



using namespace std;
int flag;
char MAP[LONG+5][LONG+5];
struct person {
    int x;
    int y;
}player;



void sxmap() {
    system("cls");
    if (player.y==LONG-1&&player.x==LONG-1) {
        flag=1;
        return;
    }

    for(int i=1;i<=LONG;i++) {
        for(int j=1;j<=LONG;j++) {
            if (MAP[i][j]!=PATH) {
                cout<<MAP[i][j]<<"  ";
            }else {
                cout<<"   ";
            }
        }
        cout<<"\n";
    }
}

void create_map(int x,int y) {
    MAP[y][x]=PATH;
    int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    // 随机打乱方向 (Fisher-Yates洗牌)
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        // 交换方向
        int tempX = dirs[i][0];
        int tempY = dirs[i][1];
        dirs[i][0] = dirs[r][0];
        dirs[i][1] = dirs[r][1];
        dirs[r][0] = tempX;
        dirs[r][1] = tempY;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + 2 * dirs[i][0];  // 新位置x
        int ny = y + 2 * dirs[i][1];  // 新位置y

        // 检查边界和墙壁状态
        if (nx>0&&nx<LONG&&ny>0&&ny<LONG&&MAP[ny][nx]==WALL) {
            // 打通中间墙
            MAP[y+dirs[i][1]][x+dirs[i][0]]=PATH;

            // 如果是出口位置
            if (nx==LONG-1&&ny==LONG-1) {
                MAP[ny][nx]=EXIT;
                continue;  // 继续探索其他方向
            }

            // 递归探索新位置
            create_map(nx, ny);
        }
    }


}

void csmap() {
    cout<<"!为玩家，E为出口\n";
    Sleep(500);

    for(int i=0;i<=LONG+1;i++) {
        for(int j=0;j<=LONG+1;j++) {
            MAP[i][j]=WALL;
        }
    }
    //创造随机地图
    create_map(1,1);

    player.y=player.x=1;
    MAP[player.x][player.y]=GAMEPLAYER;

    sxmap();
}

//上下左右操控
void RIGHT() {
    if (MAP[player.y][player.x+1]!=WALL) {

        MAP[player.y][player.x]=PATH;
        MAP[player.y][player.x+1]=GAMEPLAYER;
        player.x++;
    }
    sxmap();
}

void LEFT() {
    if (MAP[player.y][player.x-1]!=WALL) {

        MAP[player.y][player.x]=PATH;
        MAP[player.y][player.x-1]=GAMEPLAYER;
        player.x--;
    }
    sxmap();
}

void DOWN() {
    if (MAP[player.y+1][player.x]!=WALL) {

        MAP[player.y][player.x]=PATH;
        MAP[player.y+1][player.x]=GAMEPLAYER;
        player.y++;
    }
    sxmap();
}

void UP() {
    if (MAP[player.y-1][player.x]!=WALL) {

        MAP[player.y][player.x]=PATH;
        MAP[player.y-1][player.x]=GAMEPLAYER;
        player.y--;
    }
    sxmap();
}



int main() {
    //srand(time(0));
    srand((unsigned int)time(NULL));
    csmap();//产生地图
    //持续移动直到结束
    while(1) {
        if (flag==1) {
            system("cls");
            cout<<"You are Winner";
            break;
        }
        if (KEY_DOWN(VK_UP)){
            UP();
            Sleep(300);
        }

        if (KEY_DOWN(VK_DOWN)){
            DOWN();
            Sleep(300);
        }

        if (KEY_DOWN(VK_LEFT)){
            LEFT();
            Sleep(300);
        }

        if (KEY_DOWN(VK_RIGHT)){
            RIGHT();
            Sleep(300);
        }



    }






    return 0;
}
