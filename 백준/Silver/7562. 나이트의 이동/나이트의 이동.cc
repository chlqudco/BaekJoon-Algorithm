#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> p;

bool visited[301][301] = { false };
int T, L, curY, curX, destY, destX;
int dp[8][2] = { {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1} };

void Insert_And_Init() {
	cin >> T;
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < L && x < L && !visited[y][x]) return true;
	return false;
}

int BFS() {
	queue<p> que;
	que.push(make_pair(curY, curX));
	visited[curY][curX] = true;

	int depth = 0;
	while (!que.empty()) {
		int que_size = que.size();
		for (int i = 0; i < que_size; i++){
			p cur = que.front(); que.pop();

			if ((cur.first == destY) && (cur.second == destX)) return depth;

			for (int j = 0; j < 8; j++){
				int nextY = cur.first + dp[j][0];
				int nextX = cur.second + dp[j][1];

				if (CanGo(nextY, nextX)) {
					visited[nextY][nextX] = true;
					que.push(make_pair(nextY, nextX));
				}
			}
		}
		depth++;
	}
	return -1;
}

void Caluclate() {
	for (int i = 0; i < T; i++){
		cin >> L;
		cin >> curY >> curX;
		cin >> destY >> destX;

		cout << BFS() << "\n";
		memset(visited, false, sizeof(visited));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}