#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char arr[256][256+1];									//切割後的陣列 
//char arr[4][4]={"ab1","ab2","ab3"};
int check[256]={0};										//決定是否列印出 
int length = 1;											//決定幾個元素 
int setnum = 0;
void PrintAns(){
	int i,dot=0;
	printf("{");
	for(i=0;i<length;i++){
		if(check[i]){
			if(dot==1)printf(",");						//子集合內的逗號 一開始不用印  
			printf("%s",arr[i]);
			dot = 1;									//第二個元素以後才要逗點 並且最後一個不用 
		}
	}
	setnum++;											//計算集合數 
	printf("}");
}
void recursive(int pos,int countflag,int temp){			//pos當下位置  count計算當下幾個立起flag  temp占存此回合印幾個 
	if(pos>length)return;								//用來檢測最後一輪 pos比應有位置多時即停止 
	if(countflag == temp){								//當flag數量跟temp一樣多時即印出 
		if(temp!=0)printf("\n");						//第一輪不用換行 (子集合之間) 
		PrintAns();										//答案印出 
		return;
	}
	check[pos]=1;										//當下位置設置flag 
	recursive(pos+1,countflag+1,temp);					//當下flag設置好(countflag+1) 向下一輪前進(pos+1) 
	check[pos]=0;										//當下設為零 
	recursive(pos+1,countflag,temp);					//向下一項找(pos+1) 但是countflag不用加 
}
int main(){
	char init[256+1];
	scanf("{%s",init);	//把 } 給吃掉了 
	int i,j=0,k;
	if(init[0]=='}'){
		printf("{}\n");
		printf("Powerset裡總共有1個集合");
		return 0;
	}
	for(i=0,k=0;i<=strlen(init);i++,k++){
		if(init[i]=='}'){
			arr[j][k+1]='\0';
			break;
		}
		if(init[i]!=','){
			arr[j][k]=init[i];
		}else{
			arr[j][k+1]='\0';
			j++;
			k=-1;	//一定要-1 不是0 
			length++;
		}
	}
	for(i=0;i<=length;i++){						//每次印幾個 flag個數個 
		recursive(0,0,i);
	}
	printf("\nPowerset裡總共有%d個集合",setnum);
} 
