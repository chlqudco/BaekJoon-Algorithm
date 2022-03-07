#include<iostream>
#include<cstring>
using namespace std;

int T, N;
int dp[11];

int DoDP(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;

	return dp[n] = DoDP(n - 3) + DoDP(n - 2) + DoDP(n - 1);
}

int main() {
	//속도 증가
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N;
		memset(dp, 0, sizeof(dp));
		cout << DoDP(N)<<"\n";
	}
}