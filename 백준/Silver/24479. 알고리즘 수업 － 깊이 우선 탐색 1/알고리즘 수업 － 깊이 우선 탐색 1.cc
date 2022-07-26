#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
// 연결리스트 기반
vector<int> graph[100001];
int visited[100001] = { 0 };
int depth = 1;

void Insert_And_Init() {
	int u, v;
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
}

void DFS(int elem) {
	visited[elem] = depth++;
	
	int size = graph[elem].size();
	for (int i = 0; i < size; i++){
		if (visited[graph[elem][i]] == 0) DFS(graph[elem][i]);
	}
}

void Caluclate() {
	DFS(R);
	for (int i = 1; i <= N; i++){
		if (visited[i] == 0) cout << "0\n";
		else cout << visited[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
