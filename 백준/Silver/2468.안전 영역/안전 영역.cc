#include <iostream>
#include <string.h>
using namespace std;

//마을에 대한 정보
int N;
int map[101][101] = { 0 };
int map_max_height = 0;

//DFS 재료
int visited[101][101] = { 0 };
int dp[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

//결과값 정보
int cur_max_height = 0;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] > map_max_height) map_max_height = map[i][j];
		}
	}
}

bool CanGo(int y, int x, int rain) {
	//방문 안했고, 강수량보다 높고, 맵 바깥 아닌 경우
	if (y >= 0 && x >= 0 && y < N && x<N && visited[y][x] == 0 && map[y][x]>rain) return true;
	return false;
}

void DFS(int y, int x, int rain) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++){
		int nextY = y + dp[i][1];
		int nextX = x + dp[i][0];

		if (CanGo(nextY, nextX, rain)) {
			DFS(nextY, nextX, rain);
		}
	}
}

void Caluclate() {
	//i만큼 비가 내림
	for (int i = 0; i <= map_max_height; i++){
		int cur_height = 0;
		//visited 초기화
		memset(visited, 0, sizeof(visited));
		//전체 마을 돌면서
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				//방문 안했고 안잠기면 DFS 실행 및 구간? 올리기
				if (visited[j][k] == 0 && map[j][k] > i) {
					cur_height++;
					DFS(j, k, i);
				}
			}
		}
		if (cur_height > cur_max_height) cur_max_height = cur_height;
	}

	cout << cur_max_height;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}