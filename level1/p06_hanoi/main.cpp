#include <bits/stdc++.h>
using namespace std;


void bh(string f,string t,string m,int h) {
    if (h==1) {
        cout<<f<<"->"<<t<<endl;
        return;
    }
    bh(f,m,t,h-1);
    cout<<f<<"->"<<t<<endl;
    bh(m,t,f,h-1);
}
int main() {
    int h;
    cin>>h;
    bh("A","C","B",h);




    return 0;
}
