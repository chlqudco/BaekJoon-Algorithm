#include <iostream>
#include <set>

using namespace std;

int N, answer = 0;
set<string> s;

void Insert_And_Init() {
	string tmp;
	cin>>N;

	for (int i = 0; i < N; i++){
		cin>>tmp;

		// 없으면
		if (s.find(tmp) == s.end()){
			answer++;
			s.insert(tmp);

			int str_len = tmp.length();
			for (int j = 0; j < str_len - 1 ; j++){
				tmp = tmp.substr(1, str_len - 1) + tmp[0];
				s.insert(tmp);
			}
		}

	}

}

void Caluclate() {
	cout<<answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}