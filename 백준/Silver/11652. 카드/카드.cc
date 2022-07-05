#include <iostream>
#include <map>
using namespace std;

int N;
map<long long, int> m;

void Insert_And_Init() {
	long long tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		m[tmp]++;
	}
}

void Caluclate() {
	long long maxKey = 0;
	int maxValue = 0;
	for (auto i = m.begin(); i != m.end(); i++){
		//더 많이 나왔으면
		if (maxValue < i->second) {
			maxKey = i->first;
			maxValue = i->second;
		}
	}
	cout << maxKey;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}