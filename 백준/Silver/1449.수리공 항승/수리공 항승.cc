#include <iostream>
using namespace std;

//물 새는 곳 표시용, true면 물 새는 중
bool map[1001] = { false };
int N, L;

void Insert_And_Init() {
	int leakIdx;
	cin >> N >> L;
	for (int i = 0; i < N; i++){
		cin >> leakIdx;
		map[leakIdx] = true;
	}
}

void Caluclate() {
	int tapeCnt = 0;
	//파이프 쭉 돌면서 물새면 테이프 붙이기
	for (int i = 0; i < 1001; i++){
		if (map[i] == true) {
			for (int j = 0; j < L; j++){
				if (i + j > 1000) break;
				map[i + j] = false;
			}
			tapeCnt++;
		}
	}

	cout << tapeCnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}