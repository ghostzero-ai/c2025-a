#include <bits/stdc++.h>
using namespace std;
int main() {
    int su[1005];
    clock_t start=clock();
    for (int i=2;i<=1000;i++) {
        su[i]=0;
    }
    for (int i=2;i<=1000;i++) {
        for (int j=2;i*j<=1000;j++) {
            su[i*j]=1;
        }
    }
    for (int i=2;i<=1000;i++) {
        if (!su[i]) {
            cout<<i<<endl;
        }
    }
    clock_t end=clock();
    double time_used=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<time_used<<endl;
    return 0;
}
