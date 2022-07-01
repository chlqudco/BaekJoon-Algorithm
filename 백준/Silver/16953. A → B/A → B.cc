#include<iostream>
using namespace std;

long long A, B;
int cnt = -1;

void calculate(long long a, long long b, int depth) {
	if (a == b) {
		if (cnt>depth || cnt==-1){
			cnt = depth;
		}
		return;
	}
	if (a > b) return;

	calculate(a * 2, b, depth + 1);
	calculate((a * 10) + 1 , b, depth + 1);
}

int main() {
	//속도 증가
	ios_base::sync_with_stdio(false);

	cin >> A >> B;

	calculate(A, B, 0);

	if (A == B) cout << 1;
	else if (cnt == -1) cout << -1;
	else cout << cnt+1;

	return 0;
}
