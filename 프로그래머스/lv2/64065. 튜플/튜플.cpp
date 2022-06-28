#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> p;

vector<int> solution(string s) {
	vector<int> answer;
	map<int,int> tmp;
	priority_queue<p, vector<p>, less<p>> pq;

	int s_len = s.length();

	string num = "";
	for (int i = 0; i < s_len; i++){
		//숫자면 일단 이어
		if ('0' <= s[i] && s[i] <= '9') num += s[i];
		//숫자 아닌데 num에 숫자가 있으면 변환
		else {
			if (num != "") {
				int cur = stoi(num);
				tmp[cur]++;
				num = "";
			}
		}
	}

	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		pq.push(make_pair(i->second, i->first));
	}

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		answer.push_back(cur.second);
	}

	return answer;
}