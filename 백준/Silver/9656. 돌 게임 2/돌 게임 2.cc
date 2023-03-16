#include <iostream>
using namespace std;

int N;
string dp[1001];

void Insert_And_Init() {
	cin >> N;

	//dp 정리
	dp[1] = "CY";
	dp[2] = "SK";
	dp[3] = "CY";
	dp[4] = "SK";
	dp[5] = "CY";
	dp[6] = "SK";
	dp[7] = "CY";
	dp[8] = "SK";
	for (int i = 4; i < 1001; i += 3){
		dp[i] = "SK";
	}
}


void Calculate() {
	if (N % 2 == 0) cout << "SK";
	else cout << "CY";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}