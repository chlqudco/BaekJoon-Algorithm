#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int N = board.size();

	vector<int> bucket;
	int moves_size = moves.size();
	for (int i = 0; i < moves_size; i++){
		//어디서 뽑는지
		int cur = moves[i] - 1;

		//뽑기
		int doll = 0;
		for (int j = 0; j < N; j++){
			//인형 있으면
			if (board[j][cur] != 0) {
				doll = board[j][cur];
				board[j][cur] = 0;
				break;
			}
		}

		//버켓에 옮기기
		if (doll != 0) {
			//맨  위랑 나랑 같으면 점수 추가
			if ((bucket.size() > 0) && (bucket[bucket.size() - 1] == doll)) {
				bucket.pop_back();
				answer++;
			}
			else {
				bucket.push_back(doll);
			}
		}
	}

	//마지막 점수 계산
	while (bucket.size() > 1) {
		if (bucket[bucket.size() - 1] == bucket[bucket.size() - 2]) {
			bucket.pop_back();
			bucket.pop_back();
			answer++;
		}
		else {
			break;
		}
	}

	return answer*2;
}