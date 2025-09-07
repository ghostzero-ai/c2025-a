#include <bits/stdc++.h>
using namespace std;
int main() {
    int su[105],flag;

    for (int i=2;i<=100;i++) {
        su[i]=0;
    }
    for (int i=2;i<=100;i++) {
        for (int j=2;i*j<=100;j++) {
            su[i*j]=1;
        }
    }
    for (int i=4;i<=100;i+=2) {
        flag=1;
        for (int j=2;j*2<=i;j++) {
            if (su[j]==0&&su[i-j]==0) {
                //cout<<j<<" "<<i-j<<endl;可行的组合
                flag=0;
                break;
            }

        }
        if (flag) {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}
