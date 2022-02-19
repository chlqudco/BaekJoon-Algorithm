#include <iostream>
#include <vector>
using namespace std;

int N, M, a, b;

//DFS 준비물(연결리스트 방식)
int visited[101] = { 0 };
//연결리스트
vector<int> list[101];

void Insert_And_Init() {
	int x, y;

	cin >> N >> a >> b >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		list[x].push_back(y);
		list[y].push_back(x);
	}
}

void DFS(int idx, int cnt) {
	visited[idx] = cnt;

	for (int i = 0; i < list[idx].size(); i++){
		if (visited[list[idx][i]] == 0) DFS(list[idx][i], cnt + 1);
	}
}

void Caluclate() {
	//DFS 돌리기
	DFS(a, 1);

	//b에 방문 했으면 값 출력
	if (visited[b] != 0) cout << visited[b] - 1;
	else cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}