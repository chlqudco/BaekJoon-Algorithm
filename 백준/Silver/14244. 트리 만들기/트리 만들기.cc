#include <iostream>

using namespace std;

int n, m;

void Insert_And_Init() {
	cin >> n >> m;
}

void Calculate() {
	for (int i = 0; i < m - 1; i++) cout << i << ' ' << m - 1 << '\n';
	for (int i = m - 1; i < n - 1; i++) cout << i << ' ' << i + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}