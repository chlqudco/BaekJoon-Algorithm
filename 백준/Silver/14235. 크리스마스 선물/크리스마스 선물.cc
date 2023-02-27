#include <iostream>
#include <queue>

using namespace std;

int n, a;
priority_queue<int, vector<int>, less<int>> pq;

void Insert_And_Init() {
	cin >> n;
}

void Calculate() {
	int tmp;

	//n번 반복
	for (int i = 0; i < n; i++){

		//선물 입력 받기
		cin >> a;

		if (a == 0) {
			//가장 큰 선물 주기
			if (!pq.empty()) {
				cout << pq.top() << "\n"; pq.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else {
			for (int j = 0; j < a; j++) {
				cin >> tmp;
				pq.push(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}