#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int array_size = array.size();
	//커맨드 길이만큼 반복
	for (int i = 0; i < commands.size(); i++){
		priority_queue<int, vector<int>, greater<int>> pq;
		int s = commands[i][0] - 1;
		int e = commands[i][1] - 1;
		int k = commands[i][2] - 1;
		for (int j = 0; j < array_size; j++){
			if (j >= s && j <= e) pq.push(array[j]);;
		}
		for (int j = 0; j < k; j++) pq.pop();
		answer.push_back(pq.top());
	}

	return answer;
}