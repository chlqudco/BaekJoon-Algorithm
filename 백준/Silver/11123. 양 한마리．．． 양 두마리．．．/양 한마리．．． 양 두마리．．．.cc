#include <iostream>
#include <string.h>
using namespace std;

int T, H, W;
char map[101][101];
bool visited[101][101] = { false };
int dp[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void Insert_And_Init() {
	cin >> T;
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < H && x < W && !visited[y][x] && map[y][x] == '#') return true;
	return false;
}

void DFS(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++){
		int nextY = y + dp[i][0];
		int nextX = x + dp[i][1];

		if (CanGo(nextY, nextX)) DFS(nextY, nextX);
	}
}

void Caluclate() {
	string tmp;
	for (int q = 0; q < T; q++){
		cin >> H >> W;
		//맵 입력
		for (int i = 0; i < H; i++){
			cin >> tmp;
			for (int j = 0; j < W; j++){
				map[i][j] = tmp[j];
			}
		}

		//DFS
		int cnt = 0;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (!visited[i][j] && map[i][j] == '#') {
					DFS(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
		memset(visited, false, sizeof(visited));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
