#include <string>
#include <vector>

using namespace std;

int one[5] = { 1,2,3,4,5 };
int two[8] = { 2,1,2,3,2,4,2,5 };
int three[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int cnt[3] = {0};

	int answers_len = answers.size();
	for (int i = 0; i < answers_len; i++){
		int cur_answer = answers[i];
		if (one[i % 5] == cur_answer) cnt[0]++;
		if (two[i % 8] == cur_answer) cnt[1]++;
		if (three[i % 10] == cur_answer) cnt[2]++;
	}

	int max_cnt = cnt[0];
	if (max_cnt < cnt[1]) max_cnt = cnt[1];
	if (max_cnt < cnt[2]) max_cnt = cnt[2];

	for (int i = 0; i < 3; i++) {
		if (max_cnt == cnt[i]) answer.push_back(i + 1);
	}

	return answer;
}