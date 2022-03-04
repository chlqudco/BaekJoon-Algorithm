#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, minMoney = -1;
int P[51] = { 0 };
//dp[i] = i원 일때의 최대의 방 번호를 string으로 저장, 예제 4번때문에;
string dp[51];

void Insert_And_Init() {
	cin >> N;

	//못만드는 곳은 -1로
	for (int i = 0; i < 51; i++) dp[i] = "-1";

	for (int i = 0; i < N; i++){
		cin >> P[i];
		dp[P[i]] = to_string(i);
		minMoney = min(P[i], minMoney);
	}

	cin >> M;
}

void Caluclate() {
	//전체 돈 돌면서
	for (int i = minMoney+1; i <= M; i++){
		//가치들 돌기
		for (int j = 0; j < N; j++){
			int curMoney = P[j];
			//음수거나 없으면 건너뛰기
			if (i <= curMoney) continue;
			if (dp[i - curMoney] == "-1") continue;
			//있으면 최대치 조사
			
			string tmp = dp[i - curMoney] + to_string(j);
			if (tmp[0] == '0') tmp = tmp.substr(1);

			if (dp[i].length() > tmp.length()) continue;

			if (dp[i].length() < tmp.length()) dp[i] = tmp;
			else dp[i] = max(tmp, dp[i]);
		}
	}
	string result = "0";
	for (int i = 0; i <= M; i++){
		if (dp[i] == "-1") continue;
		//cout << dp[i] << "\n";
		if (result.length() < dp[i].length()) result = dp[i];
		else if (result.length() > dp[i].length()) continue;
		else result = max(dp[i], result);
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
