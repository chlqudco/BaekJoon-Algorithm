#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

p arr[100001];
int T, N, min_second, cnt;

void Insert_And_Init() {
	cin >> T;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		cin >> N;
		for (int j = 0; j < N; j++) cin >> arr[j].first >> arr[j].second;
		sort(arr, arr + N);
		cnt = 1;
		min_second = arr[0].second;
		for (int j = 1; j < N; j++) {
			if (min_second > arr[j].second) {
				min_second = arr[j].second;
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