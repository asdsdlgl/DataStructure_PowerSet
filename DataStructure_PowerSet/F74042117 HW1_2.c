#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char arr[256][256+1];									//���Ϋ᪺�}�C 
//char arr[4][4]={"ab1","ab2","ab3"};
int check[256]={0};										//�M�w�O�_�C�L�X 
int length = 1;											//�M�w�X�Ӥ��� 
int setnum = 0;
void PrintAns(){
	int i,dot=0;
	printf("{");
	for(i=0;i<length;i++){
		if(check[i]){
			if(dot==1)printf(",");						//�l���X�����r�� �@�}�l���ΦL  
			printf("%s",arr[i]);
			dot = 1;									//�ĤG�Ӥ����H��~�n�r�I �åB�̫�@�Ӥ��� 
		}
	}
	setnum++;											//�p�ⶰ�X�� 
	printf("}");
}
void recursive(int pos,int countflag,int temp){			//pos��U��m  count�p���U�X�ӥ߰_flag  temp�e�s���^�X�L�X�� 
	if(pos>length)return;								//�Ψ��˴��̫�@�� pos��������m�h�ɧY���� 
	if(countflag == temp){								//��flag�ƶq��temp�@�˦h�ɧY�L�X 
		if(temp!=0)printf("\n");						//�Ĥ@�����δ��� (�l���X����) 
		PrintAns();										//���צL�X 
		return;
	}
	check[pos]=1;										//��U��m�]�mflag 
	recursive(pos+1,countflag+1,temp);					//��Uflag�]�m�n(countflag+1) �V�U�@���e�i(pos+1) 
	check[pos]=0;										//��U�]���s 
	recursive(pos+1,countflag,temp);					//�V�U�@����(pos+1) ���Ocountflag���Υ[ 
}
int main(){
	char init[256+1];
	scanf("{%s",init);	//�� } ���Y���F 
	int i,j=0,k;
	if(init[0]=='}'){
		printf("{}\n");
		printf("Powerset���`�@��1�Ӷ��X");
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
			k=-1;	//�@�w�n-1 ���O0 
			length++;
		}
	}
	for(i=0;i<=length;i++){						//�C���L�X�� flag�Ӽƭ� 
		recursive(0,0,i);
	}
	printf("\nPowerset���`�@��%d�Ӷ��X",setnum);
} 
