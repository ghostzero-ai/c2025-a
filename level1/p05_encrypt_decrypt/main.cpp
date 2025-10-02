#include <bits/stdc++.h>
using namespace std;

//加密
string am(string md) {
    int len = md.length();
    string mw;
    //位移并倒序
    for (int i = 0; i < len; i++) {
        mw+=(md[len-1-i]+(i%5)*3+2);
    }

    return mw;


}


//解密
string jm(string md) {
    int len = md.length();
    string mw;

    for (int i = 0; i < len; i++) {
        mw+=(md[len-1-i]-2-((len-1-i)%5)*3);
    }

    return mw;

}


int main() {
    string md,mm;
    while (true) {
        printf("需要加密输入1，需要解密输入2, 退出输入3");
        int xh;
        cin>>xh;
        if (xh==3) {
            return 0;
        }
        while (xh!=1&&xh!=2) {
            printf("输入错误，请重新输入\n");
            printf("需要加密输入1，需要解密输入2");
            cin>>xh;
        }

        if (xh==1) {
            printf("请输入需要加密的密文");
            cin>>md;
            cout<<am(md);
        }
        else if (xh==2) {
            cout<<"请输入需要解密的密文";
            cin>>mm;
            cout<<jm(mm);
        }
    }






    return 0;
}
