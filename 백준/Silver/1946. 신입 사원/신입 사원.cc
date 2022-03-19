#include <iostream>
using namespace std;

int arr[100001];
int T, N, cnt,min_second;

void Insert_And_Init() {
	cin >> T;
}

void Calculate() {
	int a, b;
	for (int i = 0; i < T; i++){
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> a >> b;
			arr[a] = b;
		}
		cnt = 1;
		min_second = arr[1];
		for (int j = 2; j <= N; j++) {
			if (min_second > arr[j]) {
				min_second = arr[j];
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}