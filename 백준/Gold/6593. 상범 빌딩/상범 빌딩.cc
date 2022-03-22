#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, pair<int, int>> p;

int L, R, C;

//BFS
char map[31][31][31];
int visited[31][31][31] = { 0 };
queue<p> que;

//z y x
int dp[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,0,1}, {0,-1,0}, {0,0,-1} };
int startZ, startY, startX;
int destZ, destY, destX;

void Insert_And_Init() {
	cin >> L >> R >> C;
}

void Insert() {
	string tmp;
	for (int i = 0; i < L; i++){
		for (int j = 0; j < R; j++){
			cin >> tmp;
			if (tmp[0] == '\n') continue;
			for (int k = 0; k < C; k++){
				map[i][j][k] = tmp[k];
				if (tmp[k] == 'S') {
					startZ = i;
					startY = j;
					startX = k;
				}
				else if (tmp[k] == 'E') {
					destZ = i;
					destY = j;
					destX = k;
				}
			}
		}
	}
}

bool CanGo(int z, int y, int x) {
	if (z >= 0 && y >= 0 && x >= 0 && z < L && y < R && x < C && visited[z][y][x] == 0 && map[z][y][x] != '#') return true;
	return false;
}

void BFS() {
	visited[startZ][startY][startX] = 1;
	que.push(make_pair(startZ, make_pair(startY, startX)));

	while (!que.empty()) {
		p cur = que.front(); que.pop();

		for (int i = 0; i < 6; i++){
			int nextZ = cur.first + dp[i][0];
			int nextY = cur.second.first + dp[i][1];
			int nextX = cur.second.second + dp[i][2];

			if (CanGo(nextZ, nextY, nextX)) {
				visited[nextZ][nextY][nextX] = visited[cur.first][cur.second.first][cur.second.second] + 1;
				que.push(make_pair(nextZ, make_pair(nextY, nextX)));
			}
		}
	}
}

void Calculate() {
	while (L != 0 && R != 0 && C != 0) {
		Insert();

		BFS();

		if (visited[destZ][destY][destX] != 0) cout << "Escaped in " << visited[destZ][destY][destX] - 1 << " minute(s).\n";
		else cout << "Trapped!\n";

		memset(visited, 0, sizeof(visited));

		cin >> L >> R >> C;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}