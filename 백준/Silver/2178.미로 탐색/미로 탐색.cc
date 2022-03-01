#pragma warning(disable:4996)
#include<iostream>
#include<queue>
using namespace std;

pair<int, int> tmpPoint;
queue<pair<int,int>> que;
int N, M;
int maze[100][100] = { 0 };
int visited[100][100] = { 0 };
int dp[4][2] = { {1,0},{-1,0},{0,1 },{0,-1} };

void Insert() {
	string tmp;
	cin >> N >> M;
	//미로 입력
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '1') maze[i][j]++;
		}
	}
}

void BFS(int y, int x) {
	que.push(make_pair(y,x));
	visited[y][x] = 1;
	while (!que.empty()) {
		tmpPoint = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int tmpx = tmpPoint.second + dp[i][1];
			int tmpy = tmpPoint.first + dp[i][0];
			if (tmpx >= 0 && tmpx < M && tmpy >= 0 && tmpy < N && maze[tmpy][tmpx] == 1 && visited[tmpy][tmpx] == 0) {
				visited[tmpy][tmpx] = visited[tmpPoint.first][tmpPoint.second] + 1;
				que.push(make_pair(tmpy, tmpx));
			}
		}
	}
}

int main() {
	//속도 증가
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Insert();
	BFS(0, 0);

	cout << visited[N - 1][M - 1];
}