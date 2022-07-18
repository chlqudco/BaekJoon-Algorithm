#include<iostream>
#include<algorithm>
using namespace std;

int N;
int weight[1000];

bool CanMake(int w) {
	int total = 0;
	for (int i = N-1; i >= 0; i--){
		if (total+weight[i] <= w){
			total += weight[i];
			if (total == w) return true;
		}
	}
	return false;
}

void Calculate() {
	sort(weight, weight + N);
	int w = 1;

	for (int i = 0;;i++) {
		//w를 만들수 없으면 출력
		if (!CanMake(w)) {
			cout << w << "\n";
			break;
		}
		//만들수 있으면
		w += weight[i];
	}
}

int main() {
	//속도 증가
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> weight[i];
	}

	Calculate();
}