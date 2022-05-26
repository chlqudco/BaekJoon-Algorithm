#include <iostream>
#include <queue>
using namespace std;

int N;

//bfs
bool graph[501][501];
int visited[501] = { 0 };
queue<int> que;

void Insert_And_Init() {
	int M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
}

int BFS(int idx) {
	int friends = 0;

	visited[1] = 1;
	que.push(1);

	while(!que.empty()){
		int cur = que.front(); que.pop();
		if (visited[cur] == 3) continue;
		for (int i = 1; i <= N; i++){
			if (graph[cur][i] && visited[i] == 0) {
				visited[i] = visited[cur] + 1;
				que.push(i);
				friends++;
			}
		}
	}
	return friends;
}

void Caluclate() {
	cout << BFS(1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}