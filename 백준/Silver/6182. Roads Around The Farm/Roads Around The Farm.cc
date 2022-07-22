#include <iostream>
using namespace std;

int N, K;
int total = 0;

void recur(int num) {
	//base case
	//1. 둘다 홀수가 아니거나 짝수가 아닌경우
	if (num % 2 == 1 && K % 2 == 0) {
		total++;
		return;
	}
	if (num % 2 == 0 && K % 2 == 1) {
		total++;
		return;
	}

	bool flag = false;
	int a = 1; int b = num - 1;
	for (int i = 0; i <= num/2; i++){
		if (b - a == K) {
			flag = true;
			break;
		}
		a++;
		b--;
	}
	//recur case
	if (flag) {
		recur(a);
		recur(b);
	}
	else {
		total++;
	}
}

void Insert_And_Init() {
	cin >> N >> K;
}

void Caluclate() {
	recur(N);
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
