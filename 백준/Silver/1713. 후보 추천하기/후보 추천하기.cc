#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//추천 횟수, 들어간 순서, 학생번호
typedef pair<int, pair<int, int>> p;

//우선순위 큐 비교함수
struct compare
{
	bool operator()(p a, p b) {
		//일단 추천수 오름차순
		if (a.first != b.first) return a.first > b.first;
		//추천 수 같으면 들어간 순서로
		return a.second.first > b.second.first;
	}
};

int N, M;
vector<p> frame;

void Input_And_Init() {
	cin >> N >> M;
}

void Calculate() {
	//현재 추천받은 후보 이름
	int num;
	//비어있는 액자 개수
	int empty_frame_cnt = N;

	//총 추천 횟수만큼 반복
	for (int i = 0; i < M; i++){
		//벡터 사이즈 백업
		int frame_size = frame.size();

		//정렬하기
		sort(frame.begin(), frame.end(), compare());


		//플래그
		bool flag = false;

		//현재 추천 후보 입력 받기
		cin >> num;
	
		//이미 있는 경우
		for (int j = 0; j < frame_size; j++){
			if (frame[j].second.second == num) {
				frame[j].first++;
				flag = true;
				break;
			}
		}

		//이미 있는 경우였으면 다음 추천 받기
		if (flag) continue;

		//비어있는 사진틀이 있는 경우 그냥 넣어야 함
		if (frame.size() < N) frame.push_back(make_pair(1, make_pair(i, num)));

		//빈 곳이 없으면 추천 횟수 가장 적은 학생 삭제, 여러명이면 오래된 놈부터 삭제
		else {
			frame.pop_back();
			frame.push_back(make_pair(1, make_pair(i, num)));
		}

	}

	//출력 하기 위해 옮기기
	vector<int> answer;
	for (int i = 0; i < frame.size(); i++){
		answer.push_back(frame[i].second.second);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}