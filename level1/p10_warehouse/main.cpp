#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void show();
void add();
void ex();
void finish();

struct goods {
    string name;
    string type_number;
    int number;
}store[100005];
int count;

void show() {
    system("cls");
    for (int i=1;i<=count;i++) {
        cout<<store[i].name<<" "<<store[i].type_number<<" "<<store[i].number<<"\n";
    }
}

void add() {
    cout<<"请输入入库货物的名字，型号，数量";
    int flag=0;
    for (int i=1;i<=count;i++) {
        if () {
            flag=1;

        }
    }
    if ((flag==0)) {
        count++;
        cin>>store[count].name>>store[count].type_number>>store[count].number;
    }

}
void ex() {
    cout<<"请输入出库货物的型号，数量";
}

int main() {
    string name_add;
    int number_add,n;
    cout<<"请输入\n1显示存货列表\n2入库\n3出库\n4退出程序\n";
    Sleep(2000);
    while (1) {

        cin>>n;

        switch (n) {
            case 1:
                show();
                break;

            case 2:
                add();
                show();
                break;

            case 3:
                ex();
                show();
                break;

            case 4:
                finish();
                break;


            default:
                cout<<"wrong input\n";
        }

    }


    printf("hello world!\n");
    return 0;
}
