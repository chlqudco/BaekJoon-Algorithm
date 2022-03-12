#include <iostream>
using namespace std;

int n, k;
int coin[101] = { 0 };
int dp[10001] = { 0 };

void Insert_And_Init() {
	int tmp;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coin[i];
	//0원을 만드는 방법이 1개 있음
	dp[0] = 1;
}


void Caluclate() {
	//전체 동전을 순회 하면서
	for (int i = 0; i < n; i++){
		//그 동전으로 j원을 만들 수 있니?
		for (int j = coin[i]; j <= k; j++){
			//만들 수 있으면 dp[j-coin[i]] 에 0이 없음
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}