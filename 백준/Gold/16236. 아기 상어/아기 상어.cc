#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> p;

int N, totalSec = 0;
int map[21][21] = { 0 };

//최근접 상어 정보
int close_y = -1, close_x = -1, close_len = 999;

//아기 상어 정보
int baby_size = 2, baby_y, baby_x, eat_cnt = 0;

//BFS
int visited[21][21] = { false };
queue<p> que;
int dp[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby_y = i;
				baby_x = j;
			}
		}
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < N && map[y][x]!=9 && visited[y][x] == 0 && map[y][x] <= baby_size) return true;
	return false;
}

void BFS() {
	visited[baby_y][baby_x] = 0;
	que.push(make_pair(baby_y, baby_x));

	while (!que.empty()) {
		p cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++){
			int nextY = cur.first + dp[i][0];
			int nextX = cur.second + dp[i][1];

			if (CanGo(nextY, nextX)) {
				visited[nextY][nextX] = visited[cur.first][cur.second] + 1;
				que.push(make_pair(nextY, nextX));
			}
		}
	}
}

void CheckCloseFish() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			//먹을 수 있고 방문 했고 더 가까워야 함
			if ((map[i][j] != 0) && (map[i][j] < baby_size) && (visited[i][j] != 0) && (close_len > visited[i][j])) {
				close_y = i;
				close_x = j;
				close_len = visited[i][j];
			}
		}
	}
}

void EatCloseFish() {
	totalSec += close_len;
	map[baby_y][baby_x] = 0;
	map[close_y][close_x] = 9;
	baby_y = close_y;
	baby_x = close_x;
	eat_cnt++;
}

void Calculate() {
	while (true){
		//1. 먹을 수 있는 물고기 있는지 확인
		BFS();
		
		//2. 가장 가까운 물고기 확인
		CheckCloseFish();
		
		//2-1. 없으면 끝
		if (close_y == -1 && close_x == -1) break;
		
		//3. 먹기
		EatCloseFish();

		//4. 사이즈 재 측정
		if (eat_cnt == baby_size) {
			baby_size++;
			eat_cnt = 0;
		}
		
		//5. 초기화
		memset(visited, 0, sizeof(visited));
		close_x = -1; close_y = -1; close_len = 999;
	}

	cout << totalSec;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}