#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

pair<int, int> point, minPoint;
queue<pair<int, int>> que;
queue<pair<int, int>> caneat;

int N, sharkX, sharkY, sharkSize, sharkCnt, minute;
//인접 행렬 방식
int map[21][21] = { 0 };
int testmap[21][21] = { 0 };
int visited[21][21] = { 0 };
int dp[4][2] = { {1,0} , {0,-1} , {-1,0} , {0,1} };

void Insert() {
	sharkSize = 2;
	sharkCnt = 0;
	minute = 0;

	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j]==9){
				sharkY = i;
				sharkX = j;
			}
		}
	}
}


bool IsMap(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < N) return true;
	return false;
}

bool CanMove(int y, int x) {
	if(map[y][x] <= sharkSize) return true;
	return false;
}

void BFS(int y, int x) {
	visited[y][x] = 1;
	que.push(make_pair(y, x));

	while (!que.empty()) {
		point = que.front(); que.pop();
		
		for (int i = 0; i < 4; i++){
			int tmpY = point.first + dp[i][0];
			int tmpX = point.second + dp[i][1];
			//맵 안이고 갈 수 있으면 이동
			if (IsMap(tmpY, tmpX) && CanMove(tmpY, tmpX) && visited[tmpY][tmpX] == 0) {
				visited[tmpY][tmpX] = visited[point.first][point.second] + 1; 
				que.push(make_pair(tmpY, tmpX));
			}
		}
	}
}

bool IsFeed() {
	int flag=0,mindist=99999;
	//먹을 수 있는거 = 1
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] != 0 && map[i][j] != 9 && map[i][j] < sharkSize) {
				caneat.push(make_pair(i, j));
			}
		}
	}
	BFS(sharkY, sharkX);

	while (!caneat.empty()){
		point = caneat.front(); caneat.pop();
		int tmpdist = visited[point.first][point.second];
		if (tmpdist == 0) continue;
		if (tmpdist < mindist){
			flag = 1;
			mindist = tmpdist;
			minPoint = point;
		}
	}
	//memset(visited, 0, sizeof(visited));
	if (flag == 1) return true;
	return false;
}

void ProgressSomething() {
	map[sharkY][sharkX] = 0;
	sharkY = minPoint.first;
	sharkX = minPoint.second;
	map[sharkY][sharkX] = 9;
}

void EvolutionShark() {
	sharkCnt++;
	if (sharkCnt == sharkSize){
		sharkCnt = 0;
		sharkSize++;
	}
}

int main() {
	//스피드 업!
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Insert();

	//먹을게 있으면
	while (IsFeed()){
		//BFS(sharkY, sharkX);
		if (visited[minPoint.first][minPoint.second]==0) break;
		minute += visited[minPoint.first][minPoint.second] -1;
		ProgressSomething();
		EvolutionShark();
		memset(visited, 0, sizeof(visited));
	}

	cout << minute;
}
