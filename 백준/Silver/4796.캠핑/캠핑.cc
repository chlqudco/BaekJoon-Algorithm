#include <iostream>
using namespace std;

int L, P, V;

void Insert_And_Init() {
	cin >> L >> P >> V;
}

void Caluclate() {
	int cnt = 1;
	while (L + P + V != 0) {
		int total = 0;
		total = (V / P) * L;
		V = V - (V / P) * P;
		if (V < L) total += V;
		else total += L;
		cout << "Case " << cnt++ << ": " << total << "\n";
		cin >> L >> P >> V;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
