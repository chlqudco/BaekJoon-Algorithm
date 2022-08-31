#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int, int> p;

int N, M, min_length = -1;
int map[51][51] = { 0 };
vector<p> v;

void Input_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) v.push_back(make_pair(i, j));
		}
	}
}

int getMinLength(int y, int x) {
	int shark_size = v.size();
	int min_len = 987654321;
	for (int i = 0; i < shark_size; i++){
		min_len = min(min_len, max(abs(y - v[i].first), abs(x - v[i].second)));
	}
	return min_len;
}

void Calculate() {
	//모든.. 상어에서 안전거리 구하기?
	int shark_size = v.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 0) {
				min_length = max(min_length, getMinLength(i, j));
			}
		}
	}
	cout << min_length;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}