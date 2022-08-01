#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[1001][1001] = { 0 };
long long total_com = 0;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			total_com += map[i][j];
		}
	}
}

void Caluclate() {
	int start = 0, end = 10000000;
	int result = 10000000;

	while (start <= end) {
		int mid = (start + end) / 2;

		long long total = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mid > map[i][j]) total += map[i][j];
				else total += mid;
			}
		}

		//50퍼 넘으면
		if (total * 2 >= total_com) {
			result = min(result, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
