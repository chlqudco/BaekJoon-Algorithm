#include<stdio.h>

int main(){
	int a[5],i,total=0;

	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		total += a[i]*a[i];
	}
	printf("%d",total%10);
	return 0;
}