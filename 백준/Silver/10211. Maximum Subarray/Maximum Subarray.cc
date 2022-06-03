#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int X[1001] = { 0 };
int dp[1001] = { 0 };

void Input_And_Init() {
	cin >> T;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		//배열 입력
		cin >> N;
		for (int j = 0; j < N; j++) cin >> X[j];

		dp[0] = X[0];
		for (int j = 1; j < N; j++) dp[j] = max(dp[j - 1] + X[j], X[j]);

		int maxnum = dp[0];
		for (int j = 1; j < N; j++) maxnum = max(maxnum, dp[j]);
		cout << maxnum << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}