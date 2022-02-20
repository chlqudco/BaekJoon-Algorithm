#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int, pair<int,int>> p;

//토마토 정보
int M, N, H;
int fresh_tomato_num = 0;
int tomato_box[101][101][101] = { 0 };
queue<p> tomato_que;
int sec = 0;

//BFS 재료
int visited[101][101][101] = { 0 };
//위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dp[6][3] = { {-1,0,0},{1,0,0},{0,0,-1},{0,0,1},{0,-1,0},{0,1,0} };

void Insert_And_Init() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				cin >> tomato_box[i][j][k];
				if (tomato_box[i][j][k] == 0) fresh_tomato_num++;
				if (tomato_box[i][j][k] == 1) tomato_que.push(make_pair(i, make_pair(j, k)));
			}
		}
	}
}

bool CanGo(int z, int y, int x) {
	//다음 칸이 토마토 && 범위 안 벗어나게
	if (z >= 0 && y >= 0 && x >= 0 && z < H && y < N && x < M && tomato_box[z][y][x] == 0) return true;
	return false;
}

void BFS() {
	while (!tomato_que.empty()) {
		int cur_fresh_tomato_num = fresh_tomato_num;
		int queSize = tomato_que.size();
		for (int i = 0; i < queSize; i++){
			p tmp = tomato_que.front(); tomato_que.pop();

			for (int j = 0; j < 6; j++){
				int nextZ = tmp.first + dp[j][0];
				int nextY = tmp.second.first + dp[j][1];
				int nextX = tmp.second.second + dp[j][2];

				if (CanGo(nextZ, nextY, nextX)) {
					fresh_tomato_num--;
					tomato_box[nextZ][nextY][nextX] = 1;
					tomato_que.push(make_pair(nextZ, make_pair(nextY, nextX)));
				}
			}
		}
		if ((cur_fresh_tomato_num == fresh_tomato_num) && fresh_tomato_num != 0) {
			cout << -1;
			return;
		}
		sec++;
	}
	cout << sec-1;
}

void Caluclate() {
	BFS();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}