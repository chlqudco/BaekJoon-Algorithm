#include <iostream>
#include <queue>
using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> ten_pq;
priority_queue<int, vector<int>, greater<int>> no_ten_pq;


void Insert_And_Init() {
	int tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		if(tmp %10 == 0) ten_pq.push(tmp);
		else no_ten_pq.push(tmp);
	}
}

void Caluclate() {
	int total = 0;

	for (int i = 0; i < M; i++){
		if (ten_pq.empty() && no_ten_pq.empty()) break;

		if (!ten_pq.empty()) {
			int cur = ten_pq.top(); ten_pq.pop();
			if (cur == 10) {
				total++;
				i--;
				continue;
			}
			cur -= 10;
			total++;
			ten_pq.push(cur);
		}
		else {
			int cur = no_ten_pq.top(); no_ten_pq.pop();
			if (cur < 10) {
				i--;
				continue;
			}
			cur -= 10;
			total++;
			no_ten_pq.push(cur);
		}
	}

	while (!ten_pq.empty()) {
		if (ten_pq.top() == 10) total++;
		ten_pq.pop();
	}
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}