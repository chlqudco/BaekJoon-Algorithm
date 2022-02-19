#include <iostream>
using namespace std;

int N, M, a, b;

//DFS 준비물(인접행렬 방식)
int graph[101][101] = { 0 };
int visited[101] = { 0 };

void Insert_And_Init() {
	int x, y;

	cin >> N >> a >> b >> M;
	for (int i = 0; i < M; i++){
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
}

bool CanGo(int y, int x) {
	if (graph[y][x]==1 && y != x && visited[x] == 0) return true;
	return false;
}

void DFS(int idx,int cnt) {
	visited[idx] = cnt;

	for (int i = 1; i <= N; i++){
		if (CanGo(idx, i)) DFS(i, cnt + 1);
	}
}

void Caluclate() {
	//DFS 돌리기
	DFS(a,1);

	//b에 방문 했으면 값 출력
	if (visited[b] != 0) cout << visited[b] -1;
	else cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}