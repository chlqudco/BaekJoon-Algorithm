#include <iostream>
using namespace std;

int N;
string dp[1001];

void Insert_And_Init() {
	cin >> N;
}


void Calculate() {
	if (N % 2 == 0) cout << "SK";
	else cout << "CY";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}