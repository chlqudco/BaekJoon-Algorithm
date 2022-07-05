#include<iostream>
#include<map>
using namespace std;

int T,N;
map<string,int> m;
map<string,int>::iterator it;

void Insert() {
	m.clear();
	cin >> N;
	string a, b;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		it = m.find(b);
		if (it == m.end()) m.insert(make_pair(b, 1));
		else m[b]++;
	}
}

int Calculate() {
	int total = 1, cnt = 0;
	for (it = m.begin(); it != m.end(); it++) total *= (it->second+1);
	return total-1 ;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		Insert();
		cout << Calculate()<<"\n";
	}
}