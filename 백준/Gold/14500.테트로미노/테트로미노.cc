#include <iostream>
using namespace std;

int N, M;
int map[501][501] = { 0 };
int maxblock = -999;
//19개의 모든 블럭 경우의 수를 좌표로 다루기, 왼쪽 위를 원점으로... 이게 맞아?
int block[19][4][2] = { {{0,0},{0,1},{0,2},{0,3}}, {{0,0},{-1,0},{-2,0},{-3,0}}, {{0,0},{0,1},{-1,0},{-1,1}},
						{{0,0},{-1,0},{-2,0},{-2,1}}, {{0,0},{0,1},{1,1},{2,1}}, {{0,0},{1,0},{1,1},{1,2}},
						{{0,0},{0,1},{-1,1},{-2,1}}, {{0,0},{0,1},{0,2},{1,2}}, {{0,0},{0,-1},{-1,-1},{-2,-1}},
						{{0,0},{-1,0},{-1,1},{-1,2}}, {{0,0},{0,1},{0,2},{-1,2}}, {{0,0},{-1,0},{-1,1},{-2,1}},
						{{0,0},{0,1},{1,1},{1,2}}, {{0,0},{1,0},{1,1},{2,1}}, {{0,0},{0,1},{-1,1},{-1,2}},
						{{0,0},{0,1},{-1,1},{0,2}}, {{0,0},{0,1},{-1,1},{1,1}}, {{0,0},{0,1},{1,1},{0,2}},
						{{0,0},{-1,0},{-2,0},{-1,1}}};

void Insert_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}
}

bool IsIn(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M) return true;
	return false;
}

int IsMatched(int y, int x, int idx) {
	int total = 0;
	//4좌표 돌면서
	for (int i = 0; i < 4; i++){
		int nextY = y + block[idx][i][0];
		int nextX = x + block[idx][i][1];

		//현재 인덱스가 좌표 안에 있는지
		if (IsIn(nextY, nextX)) total += map[nextY][nextX];
		else return -1;
	}
	return total;
}

void Caluclate() {
	//모든 좌표 돌면서
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//19개의 블럭 놓기
			for (int k = 0; k < 19; k++){
				//블럭이 잘 들어가면
				int curnum = IsMatched(i, j, k);
				if (curnum != -1 && maxblock < curnum) maxblock = curnum;
			}
		}
	}

	cout << maxblock;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
