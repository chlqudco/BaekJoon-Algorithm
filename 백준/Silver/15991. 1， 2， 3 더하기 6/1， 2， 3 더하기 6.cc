#include <iostream>
using namespace std;

int T, N;
long long dp[100001] = { 0 };

void Input_And_Init() {
	cin >> T;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;

	for (int i = 7; i < 100001; i++) dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		cin >> N;
		cout << dp[N]  << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}