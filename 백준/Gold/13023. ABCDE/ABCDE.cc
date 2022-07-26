#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
vector<int> graph[2001];
bool visited[2001] = { false };
bool flag = false;

void Insert_And_Init() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void DFS(int elem, int depth) {
	visited[elem] = true;

	if (depth >= 4) {
		flag = true;
		return;
	}

	int size = graph[elem].size();
	for (int i = 0; i < size; i++){
		if (!visited[graph[elem][i]]) DFS(graph[elem][i], depth + 1);
	}
	visited[elem] = false;
}

void Caluclate() {
	for (int i = 0; i < N; i++){
		DFS(i,0);
		memset(visited, false, sizeof(visited));
		if (flag) {
			cout << 1;
			return;
		}
	}
	cout << 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
