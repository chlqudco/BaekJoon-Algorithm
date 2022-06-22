#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int,int>> p;

int N;

//다익스트라
int graph[126][126] = { 0 };
int cost[126][126] = { 0 };
int dp[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int INF = 987654321;


void Insert_And_Init() {
	cin >> N;
}

void InitCost() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cost[i][j] = INF;
	}
}

bool CanGo(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < N) return true;
	return false;
}

void Dijkstra(int i, int j) {
	priority_queue<p, vector<p>, greater<p>> pq;
	cost[i][j] = graph[i][j];
	pq.push(make_pair(cost[i][j], make_pair(0, 0)));

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		int dist = cur.first;
		int xIdx = cur.second.second;
		int yIdx = cur.second.first;

		if (cost[yIdx][xIdx] < dist) continue;

		for (int i = 0; i < 4; i++){
			int nextY = yIdx + dp[i][0];
			int nextX = xIdx + dp[i][1];
			int nextDist = dist + graph[nextY][nextX];

			if (CanGo(nextY, nextX) && (cost[nextY][nextX] > nextDist)) {
				cost[nextY][nextX] = nextDist;
				pq.push(make_pair(cost[nextY][nextX], make_pair(nextY, nextX)));
			}
		}
	}
}

void Caluclate() {
	int cnt = 1;
	while (N != 0) {
		//입력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cin >> graph[i][j];
		}
		InitCost();
		Dijkstra(0, 0);
		cout << "Problem " << cnt << ": " << cost[N - 1][N - 1] << "\n";
		cnt++;
		cin >> N;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}