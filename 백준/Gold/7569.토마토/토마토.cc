#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> p;
//BFS 이용

//문제 재료, 1=익은 토마토, 0 = 안익은 토마토, -1 = 토마도 없음
int M, N, H;
int fresh_tomato_num = 0;
int box[101][101][101] = { 0 };

//BFS 재료
queue<p> que;
//위 아래 왼 오 앞 뒤
int dp[6][3] = { {1,0,0}, {-1,0,0}, {0,0,-1}, {0,0,1}, {0,-1,0}, {0,1,0} };

void Insert_And_Init() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) que.push(make_pair(i, make_pair(j, k)));
				if (box[i][j][k] == 0) fresh_tomato_num++;
			}
		}
	}
}

bool Cango(int z, int y, int x) {
	if (z >= 0 && y >= 0 && x >= 0 && z < H && y < N && x < M && box[z][y][x] == 0) return true;
	return false;
}

void bfs() {
	int totalday = 1;
	//이게 필요 한가?
	while (!que.empty()) {
		//하나라도 바뀐 토마토가 있는지
		int flag = 0;
		int queSize = que.size();
		//하루마다 큐사이즈만큼
		for (int i = 0; i < queSize; i++){
			p tmp = que.front(); que.pop();
			for (int j = 0; j < 6; j++){
				int nextZ = tmp.first + dp[j][0];
				int nextY = tmp.second.first + dp[j][1];
				int nextX = tmp.second.second + dp[j][2];

				if (Cango(nextZ, nextY, nextX)) {
					flag = 1;
					fresh_tomato_num--;
					box[nextZ][nextY][nextX] = 1;
					que.push(make_pair(nextZ, make_pair(nextY, nextX)));
				}
			}
		}

		//큐에 있는거 다 뺐으면 조사
		if (fresh_tomato_num == 0) {
			cout << totalday;
			return;
		}

		if (flag == 1) totalday++;
		else {
			cout << -1;
			return;
		}
	}
	cout << -1;
}

void Caluclate() {
	if (fresh_tomato_num == 0) cout << 0;
	else bfs();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
