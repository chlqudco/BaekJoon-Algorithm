#include <iostream>
#include <algorithm>
using namespace std;

int N;
int P[1001] = { 0 };
int dp[1001] = { 0 };

void Insert_And_Init() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	dp[1] = P[1]; dp[2] = max(P[2], P[1] * 2); 
}

void Calculate() {
	for (int i = 3; i <= N; i++){
		for (int j = 1; j <= i; j++){
			dp[i] = max(P[i],max(dp[i], dp[i - j] + P[j]));
		}
	}
	cout << dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}