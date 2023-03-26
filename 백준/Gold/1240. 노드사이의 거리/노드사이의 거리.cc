#include <iostream>
#include <string.h>
using namespace std;

int N, M;
int graph[1001][1001] = { 0 };
bool visited[1001] = { false };

void Insert_And_Init() {
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < N-1; i++){
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
}

void DFS(int elem, int dest, int total) {
	visited[elem] = true;

	if (elem == dest) {
		cout << total << "\n";
		return;
	}

	for (int i = 1; i <= N; i++){
		if (graph[elem][i] != 0 && !visited[i]) DFS(i, dest, total + graph[elem][i]);
	}
}

void Caluclate() {
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		DFS(a, b, 0);
		memset(visited, false, sizeof(visited));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
