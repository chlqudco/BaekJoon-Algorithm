#include <iostream>

using namespace std;

int T;
int A, B;

void Insert_And_Init() {
	cin >> T;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		cin >> A >> B;

		//2로 나누다가 둘이 같아지면 그게 공통 조상
		while (A != B) {
			if (A > B) A /= 2;
			else B /= 2;
		}
		cout << 10 * A << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}