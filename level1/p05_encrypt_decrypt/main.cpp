#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

//加密
string am(string md) {
    int len = md.length();
    string mw;
    int count = 0;
    for (int i = 0; i < len; i++) {
        mw[count]=(mw[i]+i)%128;

        for (int j=count+1;j<=count+i+1;j++) {
            int rn = rand();
            mw[j]=rn%128;

        }
        count=count+i+2;
    }

    return mw;


}


//解密
string jm() {


}


int main() {
    string md,mm;
    printf("需要加密输入1，需要解密输入2");
    int xh;
    scanf("%d",&xh);
    while (xh!=1&&xh!=2) {
        printf("输入错误，请重新输入\n");
        printf("需要加密输入1，需要解密输入2");
        scanf("%d",&xh);
    }

    if (xh==1) {
        printf("请输入需要加密的密文");
        scanf("%s",&md);
        printf("%s",am(md));
    }
    /*else if (xh==2) {
        cout<<"请输入需要解密的密文";
        cin>>mm;
        cout<<jm(mm);
    }*/
    cin>>md;




    return 0;
}
