#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;

int N, E, v1, v2;

//다익스트라
vector<p> graph[801];
int cost[801] = { 0 };
int INF = 987654321;

void InitCost() {
	for (int i = 1; i <= N; i++) cost[i] = INF;
}

void Insert_And_Init() {
	int a, b, c;
	cin >> N >> E;
	for (int i = 0; i < E; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	InitCost();
}

void Dijkstra(int start) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(make_pair(0, start));

	cost[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (cost[idx] < dist) continue;
		for (int i = 0; i < graph[idx].size(); i++){
			int nextIdx = graph[idx][i].first;
			int nextDist = graph[idx][i].second + dist;

			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Caluclate() {
	int total1 = 0;
	int total2 = 0;

	Dijkstra(1);
	if (cost[v1] == INF) {
		cout << -1;
		return;
	}
	total1 += cost[v1];
	InitCost();

	Dijkstra(v1);
	if (cost[v2] == INF) {
		cout << -1;
		return;
	}
	total1 += cost[v2];
	InitCost();

	Dijkstra(v2);
	if (cost[N] == INF) {
		cout << -1;
		return;
	}
	total1 += cost[N];
	InitCost();



	Dijkstra(1);
	if (cost[v2] == INF) {
		cout << -1;
		return;
	}
	total2 += cost[v2];
	InitCost();

	Dijkstra(v2);
	if (cost[v1] == INF) {
		cout << -1;
		return;
	}
	total2 += cost[v1];
	InitCost();

	Dijkstra(v1);
	if (cost[N] == INF) {
		cout << -1;
		return;
	}
	total2 += cost[N];
	
	if (total1 > total2) cout << total2;
	else cout << total1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}