#include <iostream>
using namespace std;

int N;
int map[65][65] = { 0 };
bool visited[65][65] = { false };
bool flag = false;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < N && !visited[y][x]) return true;
	return false;
}

void DFS(int y, int x) {
	visited[y][x] = true;

	//도착 한 경우
	if ((y == N - 1) && (x == N - 1)) {
		flag = true;
		return;
	}

	//갈수 있는 거리 계산
	int nextY = y + map[y][x];
	int nextX = x + map[y][x];

	if (CanGo(nextY, x)) DFS(nextY, x);
	if (CanGo(y, nextX)) DFS(y, nextX);
}

void Caluclate() {
	DFS(0, 0);
	if (flag) cout << "HaruHaru";
	else cout << "Hing";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
