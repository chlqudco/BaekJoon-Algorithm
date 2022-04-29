#include<iostream>
#include<string.h>
using namespace std;

int T, N, M;
int coin[10001] = { 0 };
int dp[10001] = { 0 };

void Input_And_Init() {
	cin >> T;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		//동전 입력
		cin >> N;
		for (int j = 0; j < N; j++) cin >> coin[j];
		cin >> M;

		dp[0] = 1;
		//동전 하나씩 보면서
		for (int j = 0; j < N; j++) {
			for (int k = coin[j]; k <= M; k++){
				//만들수 잇서? 그럼 더해
				dp[k] += dp[k - coin[j]];
			}
		}

		cout << dp[M] << "\n";
		//dp초기화
		memset(dp, 0, sizeof(dp));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}