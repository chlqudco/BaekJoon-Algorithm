#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

struct compare {
	bool operator()(p a, p b) {
		if (a.first != b.first) return a.first > b.first;
		return a.second > b.second;
	}
};

int N;
priority_queue<p, vector<p>, compare> pq;
priority_queue<int, vector<int>, greater<int>> anspq;

void Insert_And_Init() {
	int a, b;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		pq.push(make_pair(a, b));
	}

	anspq.push(pq.top().second); pq.pop();
}

void Calculate() {
	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();

		//추가 해야 하는 상황
		if (anspq.top() > cur.first) anspq.push(cur.second);
		//빼도 되는 상황
		else {
			anspq.pop();
			anspq.push(cur.second);
		}
	}
	cout << anspq.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}