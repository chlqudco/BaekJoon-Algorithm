#include <iostream>
using namespace std;

int N, M;
char floor1[51][51];

//DFS
bool visited[51][51] = { false };

void Input_And_Init() {
	string tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		for (int j = 0; j < M; j++) floor1[i][j] = tmp[j];
	}
}

bool CanGo(int y, int x, char curFloor) {
	if (y < N && x < M && !visited[y][x] && (curFloor == floor1[y][x])) return true;
	return false;
}

void DFS(int y, int x) {
	//방문 처리
	visited[y][x] = true;

	//다음것도 방문 가능?
	if (floor1[y][x] == '-') {
		if (CanGo(y, x + 1, '-')) DFS(y, x + 1);
	}
	else {
		if (CanGo(y + 1, x, '|')) DFS(y + 1, x);
	}
}

void Calculate() {
	int answer = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//방문 안한 경우
			if (!visited[i][j]) {
				DFS(i, j);
				answer++;
			}
		}
	}

	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}