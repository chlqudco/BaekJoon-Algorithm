#include <iostream>
using namespace std;

int N, M, maxSize = 0;
int map[9][9] = { 0 };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
//맵 백업
int tmp_map[9][9] = { 0 };

void Insert_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M && tmp_map[y][x] == 0) return true;
	return false;
}

void virus_dfs(int y, int x) {
	tmp_map[y][x] = 2;

	for (int i = 0; i < 4; i++){
		int nextY = y + dp[i][0];
		int nextX = x + dp[i][1];

		if (CanGo(nextY, nextX)) virus_dfs(nextY, nextX);
	}
}

void dfs(int cnt) {
	
	//3개 다 고른 경우
	if (cnt == 3) {
		//맵 복원
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp_map[i][j] = map[i][j];
			}
		}
		//바이러스들 침투
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (tmp_map[i][j] == 2) virus_dfs(i, j);
			}
		}

		//남은 공간 조사
		int cur_size = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp_map[i][j] == 0) cur_size++;
			}
		}
		//최대값 갱신
		maxSize = max(cur_size, maxSize);
		return;
	}

	//3개가 다 안채워 졌으면
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//빈공간이면
			if (map[i][j] == 0) {
				//벽 세우고 dfs
				map[i][j] = 1;
				dfs(cnt + 1);
				//허물기
				map[i][j] = 0;
			}
		}
	}
}

void Caluclate() {
	//완전 탐색으로 3개의 벽 설치하기
	dfs(0);

	cout << maxSize;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
