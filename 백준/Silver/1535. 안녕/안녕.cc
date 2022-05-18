#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<float, int> p;

int N;
int L[101] = { 0 };
int J[101] = { 0 };
int maxhappy = 0;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	for (int i = 0; i < N; i++) cin >> J[i];
}

void insa(int idx, bool doinsa, int sum, int hp) {
	if (idx == N) return;

	if (doinsa && hp > L[idx]) {
		sum += J[idx];
		hp -= L[idx];
	}

	maxhappy = max(maxhappy, sum);

	insa(idx + 1, true, sum, hp);
	insa(idx + 1, false, sum, hp);
}

void Caluclate() {
	
	//인사 하던지 말던지
	insa(0, true, 0, 100);
	insa(0, false, 0, 100);

	cout << maxhappy;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}