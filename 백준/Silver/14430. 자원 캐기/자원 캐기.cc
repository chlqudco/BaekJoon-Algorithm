#include <iostream>
#include <string.h>

using namespace std;

int N, M, maxRock = 0;
int map[301][301] = {0};
int dp[301][301] = {0};

void Insert_And_Init() {
	cin >> N>> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

bool CanGo(int y, int x){
	if(y >= 0 && x >= 0) return true;
	return false;
}

void MaxRock(int y, int x, int curRock){
	if(map[y][x] == 1) curRock++;

	if(dp[y][x] >= curRock) return;

	dp[y][x] = max(dp[y][x], curRock);

	//base case
	if(y == 0 && x == 0) return;

	//dp case
	//if(map[y][x] <= dp[y][x]) return;

	//recur case
	int nextX = x - 1;
	int nextY = y - 1;
	if(CanGo(y, nextX)) MaxRock(y, nextX, curRock);
	if(CanGo(nextY, x)) MaxRock(nextY, x, curRock);

}

void Caluclate() {
	MaxRock(N-1, M-1, 0);

	cout << dp[0][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}