#include <iostream>
using namespace std;

int N;
int dp[31] = { 0 };

void Insert_And_Init() {
	cin >> N;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i < 31; i++) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) dp[i] += (dp[j] * 2);
	}
}

void Calculate() {
	cout << dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}