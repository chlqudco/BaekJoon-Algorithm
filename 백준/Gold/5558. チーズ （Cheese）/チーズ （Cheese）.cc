#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> p2;

int H, W, N;
char map[1001][1001] = { 0 };
//쥐새끼 좌표
int mouseX, mouseY;
//치즈 좌표
priority_queue<p2, vector<p2>, greater<p2>> pq;
int totalTime = 0;

//BFS
queue<p> que;
int visited[1001][1001] = { 0 };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void Insert_And_Init() {
	string tmp;
	cin >> H >> W >> N;
	for (int i = 0; i < H; i++){
		cin >> tmp;
		for (int j = 0; j < W; j++)
		{
			map[i][j] = tmp[j];
			if(map[i][j] == 'S') {
				mouseX = j;
				mouseY = i;
			}
			if ('1' <= map[i][j] && map[i][j] <= '9') {
				pq.push(make_pair(map[i][j] - '0', make_pair(i, j)));
			}
		}
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < H && x < W && (visited[y][x] == 0) && (map[y][x] != 'X')) return true;
	return false;
}

void BFS() {
	visited[mouseY][mouseX] = 1;
	que.push(make_pair(mouseY, mouseX));

	while (!que.empty()) {
		p cur = que.front(); que.pop();
		for (int i = 0; i < 4; i++){
			int nextY = cur.first + dp[i][0];
			int nextX = cur.second + dp[i][1];

			//갈수 있고
			if (CanGo(nextY, nextX)) {
				visited[nextY][nextX] = visited[cur.first][cur.second] + 1;

				//목적지면 탈출
				if ((nextY == pq.top().second.first) && (nextX == pq.top().second.second)) return;			
				//아니면 계속 해
				que.push(make_pair(nextY, nextX));
			}
		}
	}
}

void Init() {
	map[mouseY][mouseX] = '.';

	mouseY = pq.top().second.first;
	mouseX = pq.top().second.second;

	memset(visited, 0, sizeof(visited));
	
	while (!que.empty()) que.pop();
	
	pq.pop();
}

void Calculate() {
	//먹을 치즈 남아있으면 반복
	while (!pq.empty()) {
		//현재 치즈 쳐먹고
		BFS();
		//총 시간 갱신하고
		totalTime += visited[pq.top().second.first][pq.top().second.second] -1;
		//초기화
		Init();
	}
	cout << totalTime;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}