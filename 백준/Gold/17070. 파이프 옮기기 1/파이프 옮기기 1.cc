#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> p;

int N;
int home[17][17] = { 0 };

p pipeHead;
p pipeTail;
int dp[3][2] = { {0,1}, {1,1}, {1,0} };

//BFS 재료
int visited[17][17] = { 0 };
queue<p> que;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> home[i][j];
		}
	}
	//pipeHead = make_pair(0, 1);
//	pipeTail = make_pair(0, 0);
}

bool CangoType0(int y, int x) {
	if (x >= 0 && y >= 0 && x < N && y < N && home[y][x] == 0) return true;
	return false;
}

bool CangoType1(int y, int x) {
	if (x >= 0 && y >= 0 && x < N && y < N && home[y][x] == 0 && home[y - 1][x] == 0 && home[y][x - 1] == 0) return true;
	return false;
}

bool CangoType2(int y, int x) {
	if (x >= 0 && y >= 0 && x < N && y < N && home[y][x] == 0) return true;
	return false;
}

void BFS(int y, int x) {
	int result = 0;
	que.push(make_pair(0, make_pair(y, x)));

	while (!que.empty()) {
		p tmp = que.front(); que.pop();
		int nextY, nextX;
		//도착 했으면
		if (tmp.second.first == N - 1 && tmp.second.second == N - 1) {
			result++;
			continue;
		}
		//타입별로 분기
		if (tmp.first == 0) {
			//가로
			nextY = tmp.second.first;
			nextX = tmp.second.second + 1;

			if (CangoType0(nextY, nextX)) {
				que.push(make_pair(0, make_pair(nextY, nextX)));
			}
			//대각선
			nextY = tmp.second.first + 1;
			nextX = tmp.second.second + 1;

			if (CangoType1(nextY, nextX)) {
				que.push(make_pair(1, make_pair(nextY, nextX)));
			}
		}
		else if (tmp.first == 1) {
			//가로
			nextY = tmp.second.first;
			nextX = tmp.second.second + 1;

			if (CangoType0(nextY, nextX)) {
				que.push(make_pair(0, make_pair(nextY, nextX)));
			}
			//세로
			nextY = tmp.second.first + 1;
			nextX = tmp.second.second;

			if (CangoType2(nextY, nextX)) {
				que.push(make_pair(2, make_pair(nextY, nextX)));
			}
			//대각선
			nextY = tmp.second.first + 1;
			nextX = tmp.second.second + 1;

			if (CangoType1(nextY, nextX)) {
				que.push(make_pair(1, make_pair(nextY, nextX)));
			}
		}
		else {
			//세로
			nextY = tmp.second.first + 1;
			nextX = tmp.second.second;

			if (CangoType2(nextY, nextX)) {
				que.push(make_pair(2, make_pair(nextY, nextX)));
			}
			//대각선
			nextY = tmp.second.first + 1;
			nextX = tmp.second.second + 1;

			if (CangoType1(nextY, nextX)) {
				que.push(make_pair(1, make_pair(nextY, nextX)));
			}
		}
	}

	cout << result;
}

void Caluclate() {
	BFS(0, 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}