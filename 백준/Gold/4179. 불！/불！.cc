#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int R, C, Jy, Jx;
char map[1001][1001];
queue<p> fire;
queue<p> JiHoon;

//BFS
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int totalTime = 0;
int visited[1001][1001] = { 0 };

void Insert_And_Init() {
	string tmp;

	cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		cin >> tmp;
		for (int j = 0; j < C; j++){
			map[i][j] = tmp[j];
			if (map[i][j] == 'J') {
				JiHoon.push(make_pair(i, j));
				Jx = j; Jy = i;
			}
			else if (map[i][j] == 'F') fire.push(make_pair(i, j));
		}
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < R && x < C && visited[y][x] == 0 && map[y][x] == '.' ) return true;
	return false;
}

bool CanGo2(int y, int x) {
	if (y >= 0 && x >= 0 && y < R && x < C && (map[y][x] == '.' || map[y][x] == 'J')) return true;
	return false;
}

bool CanEscape() {
	for (int i = 0; i < R; i++) if (map[i][0] == 'J') return true;
	for (int i = 0; i < R; i++) if (map[i][C - 1] == 'J') return true;
	for (int i = 0; i < C; i++) if (map[0][i] == 'J') return true;
	for (int i = 0; i < C; i++) if (map[R - 1][i] ==  'J') return true;
	return false;
}

int Findmin() {
	int minNum = 987654321;
	for (int i = 0; i < R; i++) if (map[i][0] == 'J') minNum = min(minNum, visited[i][0]);
	for (int i = 0; i < R; i++) if (map[i][C - 1] == 'J') minNum = min(minNum, visited[i][C - 1]);
	for (int i = 0; i < C; i++) if (map[0][i] == 'J') minNum = min(minNum, visited[0][i]);
	for (int i = 0; i < C; i++) if (map[R - 1][i] == 'J') minNum = min(minNum, visited[R - 1][i]);
	return minNum;
}

int BFS() {
	visited[Jy][Jx] = 1;

	while (!JiHoon.empty()) {
		if (CanEscape()) return 1;
		//지훈이 살아 있는 만큼
		int size = JiHoon.size();
		for (int i = 0; i < size; i++) {
			p cur = JiHoon.front(); JiHoon.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = cur.first + dp[i][0];
				int nextX = cur.second + dp[i][1];

				if (CanGo(nextY, nextX)) {
					visited[nextY][nextX] = visited[cur.first][cur.second] + 1;
					map[nextY][nextX] = 'J';
					JiHoon.push(make_pair(nextY, nextX));
				}
			}
		}

		//불씨 살아 있는 만큼
		size = fire.size();
		for (int i = 0; i < size; i++) {
			p cur = fire.front(); fire.pop();
			for (int i = 0; i < 4; i++) {
				int nextY = cur.first + dp[i][0];
				int nextX = cur.second + dp[i][1];

				if (CanGo2(nextY, nextX)) {
					map[nextY][nextX] = 'F';
					fire.push(make_pair(nextY, nextX));
				}
			}
		}

		if (CanEscape()) return 1;
	}
	return 0;
}

void Calculate() {
	if (BFS() == 0) cout << "IMPOSSIBLE";
	else cout << Findmin();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}