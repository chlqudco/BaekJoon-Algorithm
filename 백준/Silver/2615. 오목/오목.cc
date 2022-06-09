#include <iostream>
using namespace std;

int omok[19][19] = { 0 };
int cnt, step;
void Insert_And_Init() {
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 19; j++) cin >> omok[i][j];
	}
}

void Caluclate() {
	bool flag = false;
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 19; j++) {
			//k = 백, 흑
			for (int k = 1; k <= 2; k++) {
				flag = false;
				//가로
				cnt = 0, step = 0;
				while (omok[i][j + step] == k) {
					cnt++;
					step++;
					if ((j + step) == 19) break;
				}
				if (cnt == 5) {
					if (j > 0 && (omok[i][j - 1] != k)) flag = true;
					else if (j == 0) flag = true;
				}

				//세로
				cnt = 0, step = 0;
				while (omok[i + step][j] == k) {
					cnt++;
					step++;
					if ((i + step) == 19) break;
				}
				if (cnt == 5) {
					if (i > 0 && (omok[i - 1][j] != k)) flag = true;
					else if (i == 0) flag = true;
				}

				//대각1
				cnt = 0, step = 0;
				while (omok[i + step][j + step] == k) {
					cnt++;
					step++;
					if (((j + step) == 19) || ((i + step) == 19)) break;
				}
				if (cnt == 5) {
					if (i > 0 && j > 0 && (omok[i - 1][j - 1] != k)) flag = true;
					else if (i == 0 || j == 0) flag = true;
				}

				//대각2
				cnt = 0, step = 0;
				while (omok[i - step][j + step] == k) {
					cnt++;
					step++;
					if (((j + step) == 19) || ((i - step) == -1)) break;
				}
				if (cnt == 5) {
					if (i < 18 && j > 0 && (omok[i + 1][j - 1] != k)) flag = true;
					else if (i == 18 || j == 0) flag = true;
				}

				//결과 정리
				if (flag) {
					cout << k << "\n" << i + 1 << " " << j + 1;
					return;
				}
			}
		}
	}
	cout << 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}