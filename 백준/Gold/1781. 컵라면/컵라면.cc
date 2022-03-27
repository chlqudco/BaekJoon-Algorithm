#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

struct compare {
	bool operator()(p a, p b) {
		if (a.first != b.first) return a.first > b.first;
		return a.second < b.second;
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
	int second = 2;
	while (!pq.empty()){
		p cur = pq.top(); pq.pop();

		//시간 지난 애 다시 넣을지 판단
		if (cur.first < second) {
			if (anspq.top() < cur.second) {
				anspq.pop();
				anspq.push(cur.second);
			}
			continue;
		}
		//아니면 걍 박아
		else {
			anspq.push(cur.second);
		}
		second++;
	}

	long long total = 0;
	while (!anspq.empty()) {
		//cout << anspq.top() << "\n";
		total += anspq.top();
		anspq.pop();
	}
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}