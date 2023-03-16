#include<stdio.h>

int main(){
	int a,i,j,cnt=0,num;

	scanf("%d",&a);

	for(i=0;i<a;i++){
		cnt=0;
		scanf("%d",&num);
		for(j=num;j>=1;j--){
			if(num%j==0) cnt++;
		}
		printf("%d %d\n",num,cnt);
	}
}