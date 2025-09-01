#include <iostream>
using namespace std;

int main() {
	int a=30;
    while(1){
    	for(int i=0;i<=a;i++){
    		for(int j=0;j<=i;j++){
    			cout<<" ";
			}
			cout<<"a";
			for(int j=i;j<=a;j++){
    			cout<<" ";
			}
			system("cls");
		}
		
		for(int i=0;i<=a;i++){
    		for(int j=i;j<=a;j++){
    			cout<<" ";
			}
			cout<<"a";
			for(int j=0;j<=i;j++){
    			cout<<" ";
			}
			system("cls");
		}
		
	}
    
    
    
    
    
    

    return 0;
    
}
