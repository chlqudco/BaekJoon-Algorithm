#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
map<string, int> m;

void Input_And_Init() {
	string tmp;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		for (int i = 0; i < tmp.length(); i++){
			if (tmp[i] == '.') {
				m[tmp.substr(i+1, i + 100)]++;
				break;
			}
		}
	}
}

void Calculate() {
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++){
		cout << (*iter).first <<" "<< (*iter).second << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}