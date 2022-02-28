#include <iostream>
using namespace std;

int T, a, b;

void Insert_And_Init() {
	cin >> T;
}

void Caluclate() {
	for (int i = 0; i < T; i++){
		cin >> a >> b;
		int tmp = a;
		for (int j = 1; j < b; j++){
			tmp = (tmp*a);
			if (tmp % 10 == 0) tmp = 10;
			if (tmp > 10) tmp = tmp % 10;
		}
		if (tmp % 10 == 0) cout << 10 << "\n";
		else cout << tmp%10 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
