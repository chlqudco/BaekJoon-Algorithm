#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> p;

int N, M, X, Y, Z;

//다익스트라
vector<p> graph[100001];
ll cost[100001] = { 0 };
ll INF = 10000000000;


void Input_And_Init() {
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= N; i++) cost[i] = INF;
	cin >> X >> Y >> Z;
}

void Dijkstra(int start) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(make_pair(0, start));

	cost[start] = 0;

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		ll dist = cur.first; int idx = cur.second;

		if (cost[idx] < dist) continue;
		for (int i = 0; i < graph[idx].size(); i++){
			ll nextDist = dist + graph[idx][i].second;
			int nextIdx = graph[idx][i].first;

			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Dijkstra2(int start) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(make_pair(0, start));

	cost[start] = 0;

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		ll dist = cur.first; int idx = cur.second;

		if (cost[idx] < dist) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			ll nextDist = dist + graph[idx][i].second;
			int nextIdx = graph[idx][i].first;

			if (nextIdx == Y) continue;

			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Calculate() {
	ll firstCost = 0, secondCost = 0;

	Dijkstra(X);
	firstCost += cost[Y];
	for (int i = 1; i <= N; i++) cost[i] = INF;

	Dijkstra(Y);
	firstCost += cost[Z];
	for (int i = 1; i <= N; i++) cost[i] = INF;

	Dijkstra2(X);
	secondCost = cost[Z];

	if (firstCost >= INF) cout << "-1 ";
	else cout << firstCost << " ";

	if (secondCost == INF) cout << "-1";
	else cout << secondCost;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}