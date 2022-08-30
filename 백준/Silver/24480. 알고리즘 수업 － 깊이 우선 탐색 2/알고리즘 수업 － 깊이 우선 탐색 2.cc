#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;

//DFS
vector<int> graph[100001];
int visited[100001] = { 0 };
int cnt = 1;

void Input_And_Init() {
	int u, v;

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++){
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}
}

void DFS(int idx) {
	visited[idx] = cnt++;

	int v_size = graph[idx].size();
	for (int i = 0; i < v_size; i++){
		int nextIdx = graph[idx][i];
		if (!visited[nextIdx]) DFS(nextIdx);
	}
}

void Calculate() {
	DFS(R);
	for (int i = 1; i <= N; i++) cout << visited[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}