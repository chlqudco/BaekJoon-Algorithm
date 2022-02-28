#include<iostream>
using namespace std;

int N, M;
int y, x, d;
int place[51][51] = { 0 };
int clean[51][51] = { 0 };
int toleft[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };
int toforward[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int toback[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

void Insert() {
	int tmp;
	cin >> N >> M;
	cin >> y >> x >> d;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> tmp;
			place[i][j] = tmp;
			clean[i][j] = tmp;
		}
	}
}

bool isNeedClean() {
	int nextY = y + toleft[d][0];
	int nextX = x + toleft[d][1];
	if (place[nextY][nextX] == 0 && clean[nextY][nextX] == 0) return true;
	else return false;
}

void RotateLeft() {
	d--;
	if (d == -1) d = 3;
}

void GoStraight() {
	y += toforward[d][0];
	x += toforward[d][1];
}

void GoBack() {
	y += toback[d][0];
	x += toback[d][1];
}

bool isAlsoBehindIsWall() {
	int nextY = y + toback[d][0];
	int nextX = x + toback[d][1];
	if (place[nextY][nextX] == 1) return true;
	else return false;
}

int Do_Cleaning() {
	int i, clean_cnt = 0;
	while (true) {
		if (clean[y][x] == 0) { clean[y][x] = 1; clean_cnt++; }
		for (i = 0; i < 4; i++)
		{
			if (isNeedClean()) {
				RotateLeft();
				GoStraight();
				break;
			}
			else {
				RotateLeft();
				continue;
			}
		}
		if (i == 4){
			if (isAlsoBehindIsWall()) return clean_cnt;
			else GoBack();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert();

	cout<<Do_Cleaning();
}