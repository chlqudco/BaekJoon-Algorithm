#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

typedef pair<long long, string> p;

queue<p> que;
set<long long> setset;
long long s, t;

void Insert_And_Init() {
	cin >> s >> t;
}

string bfs() {
	que.push(make_pair(s, ""));
	setset.insert(s);

	while (!que.empty()) {
		p cur = que.front(); que.pop();
		setset.insert(cur.first);
		string s = cur.second;

		//base case
		if (cur.first == t) return cur.second;

		long long next;

		next = cur.first * cur.first;
		if ((setset.find(next) == setset.end())) que.push(make_pair(next, s + "*"));

		next = cur.first + cur.first;
		if ((setset.find(next) == setset.end())) que.push(make_pair(next, s + "+"));

		next = cur.first - cur.first;
		if ((setset.find(next) == setset.end())) que.push(make_pair(next, s + "-"));

		next = cur.first / cur.first;
		if ((setset.find(next) == setset.end())) que.push(make_pair(next, s + "/"));

	}
	return "";
}

void Caluclate() {
	if (s == t) cout << "0";
	else {
		string result = bfs();
		if (result == "") cout << "-1";
		else cout << result;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}