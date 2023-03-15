#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N;
priority_queue<p, vector<p>, less<p>> pq;

void Insert_And_Init() {
	int d, t;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> d >> t;
		//걸리는 시간을 기준으로 정렬
		pq.push(make_pair(t, d-1));
	}
}

void Calculate() {
	//lastDay = 적어도 이때는 시작해야 함
	int lastDay = pq.top().first - pq.top().second;
	pq.pop();
	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		if (lastDay > cur.first) {
			lastDay = cur.first - cur.second;
		}
		else {
			lastDay = lastDay - cur.second - 1;
		}
	}
	cout << lastDay - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}