#include <iostream>
#include <map>
#include <queue>
using namespace std;

int Q;
map <string, priority_queue<int, vector<int>, less<int>>> m;

void Insert_And_Init() {
	cin >> Q;
}

void Caluclate() {
	long long total = 0;
	int one_or_two, k, tmp;
	string name;
	
	for (int i = 0; i < Q; i++){
		cin >> one_or_two >> name >> k;
		//고릴라가 정보 얻음
		if (one_or_two == 1) {
			for (int j = 0; j < k; j++) {
				cin >> tmp;
				m[name].push(tmp);
			}
		}
		//고릴라한테 정보 사기
		else {
			for (int j = 0; j < k; j++){
				if (m[name].empty()) break;
				total += m[name].top();
				m[name].pop();
			}
		}
	}

	cout << total;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}