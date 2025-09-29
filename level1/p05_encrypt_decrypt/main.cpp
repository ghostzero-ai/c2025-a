#include <bits/stdc++.h>
using namespace std;

//加密
string am(string md) {
    int len = md.length();
    string mw;

    int count = 0;
    for (int i = 1; i <= len; i++) {
        mw+=(md[i]+i*3)%128;
        //cout<<"*"<<mw[i]<<"*"<<endl;
        for (int j=1;j<=i+1;j++) {
            int rn = rand();
            mw+=rn%128;

        }
        count=count+i+2;

    }
    //cout<<mw<<endl;
    return mw;


}


//解密
string jm() {


}


int main() {
    string md,mm;
    printf("需要加密输入1，需要解密输入2");
    int xh;
    cin>>xh;
    while (xh!=1&&xh!=2) {
       // printf("输入错误，请重新输入\n");
        //printf("需要加密输入1，需要解密输入2");
        cin>>xh;
    }

    if (xh==1) {
        //printf("请输入需要加密的密文");
        cin>>md;
        cout<<am(md);
    }
    /*else if (xh==2) {
        cout<<"请输入需要解密的密文";
        cin>>mm;
        cout<<jm(mm);
    }*/





    return 0;
}
