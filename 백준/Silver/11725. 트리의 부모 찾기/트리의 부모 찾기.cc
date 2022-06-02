#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int parents[100001] = { 0 };

//BFS 재료
bool visited[100001] = { false };
vector<int> graph[100001];
queue<int> que;

void Insert_And_Init() {
	int a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void BFS(int s) {
	int cur_parent = 1;
	
	visited[s] = true;
	que.push(1);

	while (!que.empty()) {
		int cur = que.front(); que.pop();

		for (int i = 0; i < graph[cur].size(); i++){
			int next = graph[cur][i];
			if (!visited[next]) {
				parents[next] = cur;
				que.push(next);
				visited[next] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++) cout << parents[i] << "\n";
}

void Caluclate() {
	BFS(1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}