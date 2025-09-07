#include<stdlib.h>
#include <stdio.h>
int main() {
    long long su;
    int flag=0;
    scanf("%lld",&su);


    for (int i=2;i*i<=su;i++) {
        if (su%i==0) {

            flag=1;
            break;
        }
    }
    if (flag==0) {
        printf("Yes");
    }else {
        printf("No");
    }



    return 0;
}
