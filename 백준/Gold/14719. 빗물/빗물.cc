#include <iostream>
using namespace std;

int H, W;
bool map[501][501] = { false };

void Input_And_Init() {
	int tmp;
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++) map[j][i] = true;
	}

}

void Calculate() {
	int total = 0;

	//모든 벽을 지나면서 왼쪽 오른쪽 쏴
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			bool flag1 = false;
			bool flag2 = false;

			if (map[i][j]) continue;

			//왼쪽
			for (int k = j - 1; k >= 0; k--) {
				if (map[i][k]) {
					flag1 = true;
					break;
				}
			}
			//오른쪽
			if (flag1) {
				for (int k = j + 1; k < W; k++){
					if (map[i][k]) {
						flag2 = true;
						break;
					}
				}
			}
			if (flag2) {
				total++;
			}
		}
	}

	//출력
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}