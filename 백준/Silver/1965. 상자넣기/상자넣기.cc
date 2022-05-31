#include <iostream>
#include <algorithm>
using namespace std;

int N;
int box[1001] = { 0 };
int dp[1001] = { 0 };

void Input_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> box[i];
	dp[0] = 1;
}

void Calculate() {
	//전체 돌면서
	for (int i = 1; i < N; i++){
		//내 직전까지 순회하면서
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			//나보다 작으면	dp 갱신
			if (box[i] > box[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	//최대값 찾기
	int maxdp = -1;
	for (int i = 0; i < N; i++) maxdp = max(maxdp, dp[i]);
	cout << maxdp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}