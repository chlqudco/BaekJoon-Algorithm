#include <iostream>
using namespace std;

int N;
int A[1001] = { 0 };
int dp[1001] = { 0 };

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	dp[0] = 1;
}

void Caluclate() {

	//전체 배열을 돌면서
	for (int i = 1; i < N; i++){
		dp[i] = 1;
		//여태까지 나온 것들중 나보다 큰애면 dp 갱신
		for (int j = 0; j < i; j++){
			if (A[i] < A[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	//젤 큰 dp값 찾기
	int maxdp = -1;
	for (int i = 0; i < N; i++) maxdp = max(maxdp, dp[i]);
	cout << maxdp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}