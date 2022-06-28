#include<stdio.h>
#include<string.h>

int calculate(char *ptr){
	int i,N=1,cur=0,total=0;
	//식 계산, 일부러 뒤에서부터 하는거임
	for(i=strlen(ptr);i>=0;i--){
		//숫자일 경우
		if('0'<=ptr[i] && ptr[i]<='9'){
			cur += (ptr[i]-'0') * N;
			N *= 10;
		}
		//+기호 일 경우
		else{
			total += cur;
			cur = 0;
			N=1;
		}
	}
	total += cur;
	return total;
}

int main(){
	int result;
	char str[51];
	char *ptr;

	//문자열 입력
	scanf("%s",str);
	
	//계산
	//-를 기준으로 문자열 분할
	ptr = strtok(str,"-");

	//첫번째 항은 따로 처리
	result = calculate(ptr);
	ptr = strtok(NULL, "-");
	//나머지 항 처리
	while (ptr != NULL)
    {
        result -= calculate(ptr);
        ptr = strtok(NULL, "-");
    }

	//출력
	printf("%d\n",result);
}