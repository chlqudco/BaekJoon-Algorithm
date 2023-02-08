#include <iostream>
using namespace std;

int M, query, x;
int arr[100] = { 0 };
long long total_num = 0;

void Insert_And_Init() {
	cin >> M;
}

void Calculate() {

	for (int i = 0; i < M; i++){
		cin >> query;

		if (query == 1) {
			cin >> x;
			total_num += x;
			int idx = 0;
			while (x > 1) {
				arr[idx] += (x % 2);
				idx++;
				x /= 2;
			}
			arr[idx] += x;
		}
		else if (query == 2) {
			cin >> x;
			total_num -= x;
			int idx = 0;
			while (x > 1) {
				arr[idx] -= (x % 2);
				idx++;
				x /= 2;
			}
			arr[idx] -= x;
		}
		else if (query == 3) {
			cout << total_num << "\n";
		}
		else {
			long long total = 0;
			int idx = 1;
			for (int i = 0; i < 100; i++){
				if (arr[i] % 2 == 1) {
					total += idx;
				}
				idx *= 2;
			}
			cout << total << "\n";
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}