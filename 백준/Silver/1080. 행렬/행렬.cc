#include <iostream>
using namespace std;

int N, M;
int first_matrix[51][51] = { 0 };
int second_matrix[51][51] = { 0 };

void Insert_And_Init() {
	string tmp;
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> tmp;
		for (int j = 0; j < M; j++) first_matrix[i][j] = tmp[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) second_matrix[i][j] = tmp[j] - '0';
	}
}

bool isMatched() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (first_matrix[i][j] != second_matrix[i][j]) return false;
		}
	}
	return true;
}

void change_matrix(int y, int x) {
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (first_matrix[i + y][j + x] == 0) first_matrix[i + y][j + x] = 1;
			else first_matrix[i + y][j + x] = 0;
		}
	}
}

void Caluclate() {
	int cnt = 0;
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 3; j++){
			if (first_matrix[i][j] != second_matrix[i][j]) {
				change_matrix(i, j);
				cnt++;
			}
		}
	}
	if (isMatched()) cout << cnt;
	else cout << "-1";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}