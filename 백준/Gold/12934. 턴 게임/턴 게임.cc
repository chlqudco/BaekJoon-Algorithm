#include<iostream>
using namespace std;

long long x, y;

void Input_And_Init() {
	cin >> x >> y;
}

void Calculate() {
	//두 합을 다 더해서 나오는지 확인
	//i = 몇턴 까지 진행해야 하는지
	long long i = 1;
	long long total = 0;
	while (true) {
		total += i;
		if (total == x + y) break;
		// 예외처리 1. 두 점수를 못만다는 경우
		if (total > x + y) {
			cout << "-1";
			return;
		}
		i++;
	}

	//최소값을 찾기 위해 윤호에게 큰 점수부터 할당
	int winCount = 0;
	long long currentTotal = 0;
	for (int j = i; j > 0; j--){
		if (currentTotal + j <= x) {
			currentTotal += j;
			winCount++;
		}
		if (currentTotal == x) break;
	}

	cout << winCount;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}