#include <iostream>
using namespace std;

int T;
long long dp[10001] = { 0 };

void Input_And_Init() {
	cin >> T;
	dp[0] = 1;
	dp[1] = 1;
}

void Calculate() {
	int P, Q;
	for (int i = 0; i < T; i++){
		cin >> P >> Q;

		for (int i = 2; i <= P; i++) {
			dp[i] = (dp[i - 2] + dp[i - 1]) % Q;
		}

		cout << "Case #" << i + 1 << ": " << dp[P-1] % Q << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}