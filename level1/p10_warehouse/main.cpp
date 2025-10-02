#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void show();
void add();
void ex();
void reserve();
void read(string filename);
struct goods {
    string name;
    string type_number;
    int number;
    goods(string n, string t, int num) {
        name = n;
        type_number = t;
        number = num;
    }
};

vector<goods> store;
int COUNT;



void show() {
    //system("cls");
    for (int i=0;i<COUNT;i++) {
        cout<<store[i].name<<" "<<store[i].type_number<<" "<<store[i].number<<"\n";
    }
}

void add() {
    cout<<"请输入入库货物的名字，型号，数量";
    int flag=0;
    string name,type_number;
    int number;
    cin>>name>>type_number>>number;
    for (int i=0;i<COUNT;i++) {
        if (name==store[i].name&&type_number==store[i].type_number) {
            flag=1;
            store[i].number+=number;
            break;
        }else if (name==store[i].name||type_number>store[i].type_number) {
            cout<<"检测到出现相同型号或相同名称，请问是否坚持输入\n坚持输入按1，重新输入按2";
            int jc;
            cin>>jc;
            while (jc!=1&&jc!=2) {
                cout<<"输入错误，请重新输入";
                cin>>jc;
            }
            if (jc==1) {
                break;
            }else if (jc==2) {
                add();
                return;
            }
        }
    }
    if (flag==0) {
        goods s(name,type_number,number);
        store.push_back(s);
        COUNT++;
    }

}
void ex() {
    cout<<"请输入出库货物的名字,型号，数量";
    string name,type_number;
    int number;
    cin>>name>>type_number>>number;
    for (int i=0;i<COUNT;i++) {
        if (name==store[i].name&&type_number==store[i].type_number) {
            if (store[i].number>=number) {
                store[i].number-=number;
            }else {
                cout<<"出货错误，货物数量不足，无法实现，请重新输入\n";
                ex();
            }

            break;
        }
    }
}

void reserve(string filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr<<"无法找到文件："<<filename<<endl;
        Sleep(100000);
        exit(1);
        //杀进程
    }
    for (const auto &i:store) {
        outFile<<i.name<<" "<<i.type_number<<" "<<i.number<<"\n";
    }
}

void read(string filename) {
    COUNT=0;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr<<"无法打开文件："<<filename<<endl;
        Sleep(100000);
        exit(1);
        //杀进程
    }
    string line;
    while (getline(file, line)) {
        int firstspace = line.find(' ');
        int secondspace = line.find(' ',firstspace+1);
        goods s("0/","0/",0);
        s.name = line.substr(0, firstspace);
        s.type_number = line.substr(firstspace+1,secondspace-firstspace-1);
        s.number = stoi(line.substr(secondspace+1));

        store.push_back(s);

        COUNT++;
    }

}

int main() {
    string name_add;
    int number_add,n;
    read("goods.txt");


    //Sleep(2000);

    while (1) {
        //system("cls");
        cout<<"请输入\n1显示存货列表\n2入库\n3出库\n4退出程序\n";
        cin>>n;


        switch (n) {

            case 1:

                show();

                break;

            case 2:
                add();

                break;

            case 3:
                ex();

                break;

            case 4:
                reserve("goods.txt");
                return 0;
                break;


            default:
                cout<<"wrong input\n";
        }

    }


    return 0;
}
