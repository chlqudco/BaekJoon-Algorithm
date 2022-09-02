#include <iostream>
using namespace std;

int N, kim, im;

void Input_And_Init() {
	cin >> N >> kim >> im;
	if (kim > im) {
		int tmp = kim;
		kim = im;
		im = tmp;
	}
}

void Calculate() {
	int round = 1;

	while (true) {

		//종료 조건1 : 둘이 대결하는 경우
		if (kim % 2 == 1 && im - kim == 1) break;

		//종료 조건2 : 안만나는 경우

		//다음 라운드
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;

		round++;
	}
	cout << round;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}