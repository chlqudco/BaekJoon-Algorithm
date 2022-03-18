#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int T, N;
priority_queue<p, vector<p>, greater<p>> pq;

void Insert_And_Init() {
	cin >> T;
}

void Caluclate(){
	int s, m;
	for (int i = 0; i < T; i++){
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> s >> m;
			pq.push(make_pair(s, m));
		}
		int rank = pq.top().second; pq.pop();
		int cnt = 1;
		while (!pq.empty()) {
			if (rank > pq.top().second) {
				cnt++;
				rank = pq.top().second;
			}
			pq.pop();
		}
		cout << cnt << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}