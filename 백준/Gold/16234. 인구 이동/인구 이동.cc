#include<iostream>
#include<queue>
#include<math.h>
#include<string.h>
using namespace std;

typedef pair<int, int> p;

//기본 재료
int N, L, R, unionCount;
int A[51][51] = { 0 };
//각 연합의 총 인구수
int unionTotal[2601] = { 0 };
//각 연합의 크기
int unionSize[2601] = { 0 };

//BFS 재료
int visited[51][51] = { 0 };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue<p> que;

void Input_And_Init() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
}

bool CanMove() {
	int gap1, gap2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) continue;
			else if (i == N - 1) {
				gap2 = abs(A[i][j] - A[i][j + 1]);
				if (gap2 >= L && gap2 <= R) return true;
			}
			else if (j == N - 1) {
				gap1 = abs(A[i][j] - A[i + 1][j]);
				if (gap1 >= L && gap1 <= R) return true;
			}
			else {
				gap1 = abs(A[i][j] - A[i + 1][j]);
				gap2 = abs(A[i][j] - A[i][j + 1]);

				if (gap1 >= L && gap1 <= R) return true;
				if (gap2 >= L && gap2 <= R) return true;
			}
		}
	}
	return false;
}

bool CanGo(int y, int x, int gap) {
	if (y >= 0 && x >= 0 && y < N && x < N && visited[y][x] == 0 && gap >= L && gap <= R) return true;
	return false;
}

int BFS(int y, int x) {
	unionSize[unionCount]++;

	int totalPeople = A[y][x];

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

	//인구 이동이 일어날 수 있는지
	while (CanMove()) {
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

		//3. 새로운 인구수 재정하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = unionTotal[visited[i][j]] / unionSize[visited[i][j]];
			}
		}

		day++;

		//초기화
		memset(unionSize, 0, sizeof(unionSize));
		memset(visited, 0, sizeof(visited));
		memset(unionTotal, 0, sizeof(unionTotal));
	}
	
	//이동한 날 출력
	cout << day;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}