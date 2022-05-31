#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, M, K;

//BFS
bool map[101][101] = { 0 };
bool visited[101][101] = { 0 };
int max_trash = -1;
int dp[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void Insert_And_Init() {
	int y, x;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++){
		cin >> y >> x;
		map[y - 1][x - 1] = true;
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M && map[y][x] && !visited[y][x]) return true;
	return false;
}

int BFS(int y, int x) {
	int size = 1;
	visited[y][x] = true;
	queue<p> que;
	que.push(make_pair(y, x));

	while (!que.empty()) {
		p cur = que.front(); que.pop();
		for (int i = 0; i < 4; i++){
			int nextY = cur.first + dp[i][0];
			int nextX = cur.second + dp[i][1];

			if (CanGo(nextY, nextX)) {
				size++;
				que.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = true;
			}
		}
	}
	return size;
}

void Caluclate() {
	//전체 맵 돌면서
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//방문 안했고 트루면 방문 시작
			if (map[i][j] && !visited[i][j]) {
				int cur_size = BFS(i, j);
				max_trash = max(cur_size, max_trash);
			}
		}
	}

	cout << max_trash;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}