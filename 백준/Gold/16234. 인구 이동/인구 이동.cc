#include<iostream>
#include<queue>
#include<math.h>
#include<string.h>
using namespace std;

typedef pair<int, int> p;

//기본 재료
int N, L, R, unionCount;
int A[51][51] = { 0 };
//각 연합의 총 인구수, 크기
int unionTotal[2501] = { 0 }, unionSize[2501] = { 0 };

//BFS 재료
int visited[51][51] = { 0 };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue<p> que;

void Input_And_Init() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
}

bool CanGo(int y, int x, int gap) {
	if (y >= 0 && x >= 0 && y < N && x < N && visited[y][x] == 0 && gap >= L && gap <= R) return true;
	return false;
}

int BFS(int y, int x) {
	int totalPeople = A[y][x];

	unionSize[unionCount] = 1;
	visited[y][x] = unionCount;
	que.push(make_pair(y, x));

	while (!que.empty()) {
		p cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++){
			int nextY = cur.first + dp[i][0];
			int nextX = cur.second + dp[i][1];
			int gap = abs(A[cur.first][cur.second] - A[nextY][nextX]);

			if (CanGo(nextY, nextX, gap)) {
				visited[nextY][nextX] = unionCount;
				totalPeople += A[nextY][nextX];
				que.push(make_pair(nextY, nextX));
				unionSize[unionCount]++;
			}
		}
	}
	return totalPeople;
}

void Calculate() {
	int day = 0;

	while (true) {
		//연합의 수 초기화
		unionCount = 1;
		//1. 국경선 오픈 되는곳 찾기(모든 점에서 BFS)
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				//방문하지 않았다면 BFS
				if (visited[i][j] == 0) {
					unionTotal[unionCount] = BFS(i, j);
					unionCount++;
				}
			}
		}
		//2. 연합이 안생기면 꺼져
		if (unionCount-1 == (N * N)) break;
		//3. 새로운 인구수 재정하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) A[i][j] = unionTotal[visited[i][j]] / unionSize[visited[i][j]];
		}
		//초기화
		memset(visited, 0, sizeof(visited));
		day++;
	}
	cout << day;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}