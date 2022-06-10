#include <iostream>
using namespace std;

int N;
int dp[100001] = { 0 };

void Insert_And_Init() {
	cin >> N;

	for (int i = 0; i < 100001; i++)	dp[i] = 4;
	for (int i = 1; i*i < 100001; i++) dp[i*i] = 1;
	dp[2] = 2; dp[3] = 3;

	for (int i = 4; i < 100001; i++) {
		int step = 1;
		while (i - (step*step) > 0) {
			dp[i] = min(dp[i], dp[i - (step*step)] + 1);
			step++;
		}
	}
}

void Caluclate() {
	cout << dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}