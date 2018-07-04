#include<stdio.h>
int recursive(int n){
	if(n<=1)return 1;
	return n*recursive(n-1);
}
int iterative(int n){
	int temp = 1;
	for(;n>0;n--){
		temp = temp*n; 
	}
	return temp;
}
int main(){
	int num;
	while(1){
		printf("Please enter a number bigger than 0. enter '-1' to end program.\n");
		scanf("%d",&num);
		if(num!=-1){
			printf("iterative : %d\n",iterative(num));
			printf("recursive : %d\n",recursive(num));
		}else break;
	}
} 
