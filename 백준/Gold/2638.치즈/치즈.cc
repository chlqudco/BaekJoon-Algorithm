#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

//치즈맵 준비물
int N, M, cheese_cnt=0;
int cheese_map[101][101] = { 0 };

//BFS 준비물
pair<int, int> p;
queue<pair<int, int>> que;

int visited[101][101] = { 0 };
int bfs_map[101][101] = { 0 };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void Insert_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> cheese_map[i][j];
			if (cheese_map[i][j] == 1) cheese_cnt++;
		}
	}
}

//범위 벗어나지 않고, 방문 안했고, 치즈 없어야 이동 가능
bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M && visited[y][x] == 0 && cheese_map[y][x]==0) return true;
	return false;
}

//기본적인 BFS, 공기 층은 1로
void BFS(int y, int x) {
	que.push(make_pair(y, x));
	visited[y][x] = 1;
	bfs_map[y][x] = 1;

	while (!que.empty()) {
		p = que.front(); que.pop();

		for (int i = 0; i < 4; i++){
			int nextY = p.first + dp[i][0];
			int nextX = p.second + dp[i][1];

			if (CanGo(nextY, nextX)) {
				que.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = 1;
				bfs_map[nextY][nextX] = 1;
			}
		}
	}
}

bool IsGetAway(int y, int x) {
	int air = 0;
	//4면중 2면이 공기새끼면
	for (int i = 0; i < 4; i++){
		if (bfs_map[y + dp[i][0]][x + dp[i][1]] == 1) air++;
	}
	if (air >= 2) return true;
	return false;
}

void InitBFS() {
	memset(visited, 0, sizeof(visited));
	memset(bfs_map, 0, sizeof(bfs_map));
}

void Caluclate() {
	int cur_cnt_cheese = 0;
	int sec = 0;

	while (cheese_cnt != cur_cnt_cheese) {
		//0. 1초 흐름
		sec++;
		//1. BFS 돌려서 공기층 파악
		BFS(0, 0);

		//2. 치즈 맵 돌면서 치즈 새끼들 파악 (시간초과 뜨면 치즈의 위치를 자료구조에 담기)
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (cheese_map[i][j] == 1) {
					//치즈 썩었으면
					if (IsGetAway(i, j)) {
						//치즈 없애고
						cheese_map[i][j] = 0;
						//갯수 조정
						cur_cnt_cheese++;
					}
				}
			}
		}
		//BFS 초기화
		InitBFS();
	}

	cout << sec;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}