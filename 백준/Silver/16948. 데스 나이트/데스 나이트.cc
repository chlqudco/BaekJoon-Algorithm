#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N;
int r1, c1, r2, c2;

//BFS
int dp[6][2] = { {-2,-1}, {-2,1}, {2,-1}, {2,1}, {0,-2}, {0,2} };
bool visited[201][201] = { false };
queue<p> que;

void Insert_And_Init() {
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < N && !visited[y][x]) return true;
	return false;
}

int BFS() {
	int step = 0;
	visited[r1][c1] = true;
	que.push(make_pair(r1, c1));

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++){
			p cur = que.front(); que.pop();

			if (cur.first == r2 && cur.second == c2) return step;

			for (int j = 0; j < 6; j++){
				int nextY = cur.first + dp[j][0];
				int nextX = cur.second + dp[j][1];

				if (CanGo(nextY, nextX)) {
					visited[nextY][nextX] = true;
					que.push(make_pair(nextY, nextX));
				}
			}
		}
		step++;
	}
	return -1;
}

void Caluclate() {
	cout << BFS();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
