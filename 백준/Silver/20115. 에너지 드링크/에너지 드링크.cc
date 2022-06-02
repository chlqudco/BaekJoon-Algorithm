#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

void Insert_And_Init() {
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
}

void Caluclate() {
	float total = (float)v[N-1];
	for (int i = 0; i < N-1; i++) total += ((float)v[i] / 2.0);
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}