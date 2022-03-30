#include <iostream>
#include <algorithm>
using namespace std;

int N, X;
int arr[100001] = { 0 };

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> X;
	sort(arr, arr + N);
}

void Calculate() {
	int start = 0;
	int end = N - 1;
	
	int cnt = 0;
	while (start < end) {
		int total = arr[start] + arr[end];
		if (total == X) {
			cnt++;
			start++;
		}
		else if (total < X) {
			start++;
		}
		else {
			end--;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}