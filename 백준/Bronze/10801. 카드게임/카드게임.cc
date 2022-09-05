#include<stdio.h>

int main(){
	int a[10],b[10],i,cnt1=0,cnt2=0;

	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<10;i++){
		if(a[i]>b[i]) cnt1++;
		else if(a[i]<b[i]) cnt2++;
	}

	if(cnt1>cnt2) printf("A");
	else if(cnt1<cnt2) printf("B");
	else printf("D");
}
