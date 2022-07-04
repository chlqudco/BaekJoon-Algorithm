#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int num[2001] = { 0 };

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num, num + N);
}

void Caluclate() {
	int cnt = 0;

	for (int i = 0; i < N; i++){
		int target = num[i];
		int start = 0, end = N - 1;

		bool flag = false;
		while (start < end) {
			if ((num[start] + num[end] == target) && start != i && end != i) {
				cnt++;
				break;
			}

			if (num[start] + num[end] == target) {
				if (flag) start++;
				else end--;
				flag = !flag;
			}
			else if(num[start] + num[end] > target) end--;
			else start++;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}