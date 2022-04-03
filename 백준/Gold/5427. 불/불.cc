#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair<int, int> p;

int T;
int R, C, Jy, Jx;
char map[1001][1001];
queue<p> fire;
queue<p> JiHoon;

//BFS
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int totalTime = 0;
int visited[1001][1001] = { 0 };

void Insert_And_Init() {
	cin >> T;
}

void Init() {
	string tmp;

	memset(visited, 0, sizeof(visited));
	while (!fire.empty()) fire.pop();
	while (!JiHoon.empty()) JiHoon.pop();

	cin >> C >> R;

	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[j];
			if (map[i][j] == '@') {
				JiHoon.push(make_pair(i, j));
				Jx = j; Jy = i;
			}
			else if (map[i][j] == '*') fire.push(make_pair(i, j));
		}
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < R && x < C && visited[y][x] == 0 && map[y][x] == '.') return true;
	return false;
}

bool CanGo2(int y, int x) {
	if (y >= 0 && x >= 0 && y < R && x < C && (map[y][x] == '.' || map[y][x] == '@')) return true;
	return false;
}

int BFS() {
	visited[Jy][Jx] = 1;

	while (!JiHoon.empty()) {

		//불씨 살아 있는 만큼
		int size = fire.size();
		for (int i = 0; i < size; i++) {
			p cur = fire.front(); fire.pop();
			for (int i = 0; i < 4; i++) {
				int nextY = cur.first + dp[i][0];
				int nextX = cur.second + dp[i][1];

				if (CanGo2(nextY, nextX)) {
					map[nextY][nextX] = '*';
					fire.push(make_pair(nextY, nextX));
				}
			}
		}


		//지훈이 살아 있는 만큼
		size = JiHoon.size();
		for (int i = 0; i < size; i++) {
			p cur = JiHoon.front(); JiHoon.pop();

			//다왔으면 탈출
			if (cur.first == 0 || cur.second == 0 || cur.first == R - 1 || cur.second == C - 1) return visited[cur.first][cur.second];

			for (int i = 0; i < 4; i++) {
				int nextY = cur.first + dp[i][0];
				int nextX = cur.second + dp[i][1];

				if (CanGo(nextY, nextX)) {
					visited[nextY][nextX] = visited[cur.first][cur.second] + 1;
					map[nextY][nextX] = '@';
					JiHoon.push(make_pair(nextY, nextX));
				}
			}
		}
	}
	return 0;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		Init();
		int result = BFS();
		if (result == 0) cout << "IMPOSSIBLE\n";
		else cout << result<<"\n";

	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}