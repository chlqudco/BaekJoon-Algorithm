#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int N, M, A, B;

//다익스트라
vector<p> graph[1001];
int cost[1001] = { 0 };
int INF = 987654321;
//가중치, 인덱스
priority_queue<p, vector<p>, greater<p>> pq;

void Insert_And_Init() {
	int s, e, c;

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> s >> e >> c;
		graph[s].push_back(make_pair(c, e));
	}
	cin >> A >> B;
	for (int i = 1; i <= N; i++) cost[i] = INF;
	cost[A] = 0;
}

void dijkstra() {
	pq.push(make_pair(0, A));

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		int dist = cur.first; int idx = cur.second;

		if (dist > cost[idx]) continue;

		for (int i = 0; i < graph[idx].size(); i++) {
			int nextIdx = graph[idx][i].second;
			int nextDist = dist + graph[idx][i].first;

			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Caluclate() {
	dijkstra();
	cout << cost[B];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}