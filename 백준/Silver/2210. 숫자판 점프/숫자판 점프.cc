#include <iostream>
#include <map>
using namespace std;

//용량, 현재 값
typedef pair<int, int> p;
map<int,int> m;

int numberPan[5][5] = { 0 };
int dp[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void Insert_And_Init() {
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) cin >> numberPan[i][j];
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < 5 && x < 5) return true;
	return false;
}

void DFS(int y, int x, int depth, int num) {
	if (depth == 6) {
		m[num] = 1;
		return;
	}

	for (int i = 0; i < 4; i++){
		int nextY = dp[i][0] + y;
		int nextX = dp[i][1] + x;

		if (CanGo(nextY, nextX)) DFS(nextY, nextX, depth + 1, num * 10 + numberPan[nextY][nextX]);
	}
}

void Caluclate() {
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			DFS(i, j, 1, numberPan[i][j]);
		}
	}
	cout << m.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
