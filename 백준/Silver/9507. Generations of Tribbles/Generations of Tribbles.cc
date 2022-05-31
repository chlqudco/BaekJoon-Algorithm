#include <iostream>
using namespace std;

int T;
long long koong[68] = { 0 };

void Insert_And_Init() {
	cin >> T;
	koong[0] = 1; koong[1] = 1; koong[2] = 2; koong[3] = 4;
	for (int i = 4; i < 68; i++){
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	}
}

void Caluclate() {
	int a;
	for (int i = 0; i < T; i++){
		cin >> a;
		cout << koong[a] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}