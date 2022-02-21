#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(string a, string b) {
		if (a.length() != b.length()) return a.length() > b.length();
		else {
			int a_sum=0, b_sum=0;
			for (int i = 0; i < a.length(); i++) { if ('0' <= a[i] && a[i] <= '9') a_sum += (a[i] - '0'); }
			for (int i = 0; i < b.length(); i++) { if ('0' <= b[i] && b[i] <= '9') b_sum += (b[i] - '0'); }

			if (a_sum != b_sum) return a_sum > b_sum;
		}
		return a > b;
	}
};

int N;
//I love priority queue
priority_queue<string, vector<string>, compare> pq;

void Insert_And_Init() {
	string tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		pq.push(tmp);
	}
}

void Caluclate() {
	while (!pq.empty()) {
		cout << pq.top() << "\n"; pq.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}