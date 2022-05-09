#include<stdio.h>

int N;

int main() {
	char str[101];
	char elem[101];
	char elem_cnt = 0;
	int cnt = 0, flag = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %s", str);
		//검사
		int len = strlen(str);
		elem[0] = str[0];
		elem_cnt = 1;
		flag = 0;
		for (int i = 1; i < len; i++)
		{
			//앞문자랑 똑같으면 패스
			if (str[i - 1] == str[i]) continue;
			//해당 문자가
			//elem에 같거나  있으면 안됨
			for (int j = 0; j < elem_cnt; j++)
			{
				if (str[i] == elem[j]) {
					flag = 1;
					break;
				}
			}
			elem[elem_cnt] = str[i];
			elem_cnt++;
		}
		if (flag == 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
}
