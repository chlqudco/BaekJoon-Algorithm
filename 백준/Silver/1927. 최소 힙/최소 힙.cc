#include <iostream>

#include<queue>


using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void Insert_And_Init() {
	cin >> N;
}

void Caluclate() {
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp > 0) pq.push(tmp);
		else {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}