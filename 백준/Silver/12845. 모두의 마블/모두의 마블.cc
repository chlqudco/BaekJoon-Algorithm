#include <iostream>
using namespace std;

int N;
int maxValue = -1, maxIdx = 0;
int L[100001] = { 0 };

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
		if (L[i] > maxValue) {
			maxValue = L[i];
			maxIdx = i;
		}
	}
}

void Caluclate() {
	int totalGold = 0;

	//오룬쪽으로 쭉
	for (int i = maxIdx+1; i < N ; i++) totalGold += (maxValue + L[i]);
	//왼쪽으로 쭉
	for (int i = maxIdx-1; i >= 0; i--) totalGold += (maxValue + L[i]);
	
	cout << totalGold;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}