#include <iostream>
#include <queue>
using namespace std;

int T, N;

void Insert_And_Init() {
	cin >> T;
}

void Caluclate() {
	for (int i = 0; i < T; i++){
		cin >> N;
		if (N == 1) {
			cout << "1\n";
			continue;
		}
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int j = 9; j >= 2 ; j--){
			if (N % j == 0) {
				pq.push(j);
				N /= j;
				j++;
			}
		}

		if (N != 1) cout << "-1\n";
		else cout << pq.size()<<"\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
