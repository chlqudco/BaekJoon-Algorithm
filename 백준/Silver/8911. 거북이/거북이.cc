#include <iostream>
#include <algorithm>
using namespace std;

int T;
int ymax = 0, ymin = 0, xmax = 0, xmin = 0;
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int cur_dir = 0;
int cury = 0, curx = 0;

void Insert_And_Init() {
	cin >> T;
}

void moveForward() {
	cury += dp[cur_dir][0];
	curx += dp[cur_dir][1];
}

void moveBack() {
	cury -= dp[cur_dir][0];
	curx -= dp[cur_dir][1];
}

void updateMaxMin() {
	ymax = max(ymax, cury);
	ymin = min(ymin, cury);

	xmax = max(xmax, curx);
	xmin = min(xmin, curx);
}

void initMembers() {
	ymax = 0, ymin = 0, xmax = 0, xmin = 0;
	cur_dir = 0;
	cury = 0, curx = 0;
}

void Print() {
	int ylen = ymax - ymin;
	int xlen = xmax - xmin;
	if (ylen == 0 || xlen == 0) cout << "0\n";
	else cout << ylen * xlen << "\n";
}

void Caluclate() {
	string cmd;
	for (int i = 0; i < T; i++){
		cin >> cmd;
		int len = cmd.length();

		for (int j = 0; j < len; j++) {
			char cur = cmd[j];

			if (cur == 'F') {
				moveForward();
			}
			else if (cur == 'B') {
				moveBack();
			}
			else if (cur == 'L') {
				cur_dir--;
				if (cur_dir == -1) cur_dir = 3;
			}
			else if (cur == 'R') {
				cur_dir++;
				if (cur_dir == 4) cur_dir = 0;
			}

			updateMaxMin();
		}
		Print();
		initMembers();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
