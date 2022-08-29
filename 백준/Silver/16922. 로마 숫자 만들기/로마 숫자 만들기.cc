#include <iostream>
using namespace std;

int N;
int result = 0;
bool value[21][2001] = { false };

void Input_And_Init() {
	cin >> N;
}

void recur(int depth, int total) {

	//base case
	if (depth == N) {
		if (!value[depth][total]) {
			value[depth][total] = true;
			result++;
		}
		return;
	}

	if (value[depth][total]) return;
	value[depth][total] = true;

	//recur case
	recur(depth + 1, total + 1);
	recur(depth + 1, total + 5);
	recur(depth + 1, total + 10);
	recur(depth + 1, total + 50);
}

void Calculate() {
	recur(1, 1);
	recur(1, 5);
	recur(1, 10);
	recur(1, 50);

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}