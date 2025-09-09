#include <stdio.h>


int main() {
	int cs=0;
	cs=666;
	printf("%d",cs);
	int a=120;
	while(1){
		for(int i=0;i<=a;i++){
			for(int j=0;j<=i;j++){
				printf(" ");
			}
			printf("a");
			for(int j=i;j<=a;j++){
				printf(" ");
			}
			system("cls");
		}

		for(int i=0;i<=a;i++){
			for(int j=i;j<=a;j++){
				printf(" ");
			}
			printf("a");
			for(int j=0;j<=i;j++){
				printf(" ");
			}
			system("cls");
		}

	}







	return 0;

}
