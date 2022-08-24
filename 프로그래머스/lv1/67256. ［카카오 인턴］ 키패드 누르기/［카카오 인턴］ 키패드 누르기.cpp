#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int leftX = 0, leftY = 3, rightX = 2, rightY = 3;

string solution(vector<int> numbers, string hand) {
    string answer = "";
	int num_size = numbers.size();

	for (int i = 0; i < num_size; i++){
		int cur_num = numbers[i];
		if(cur_num == 0) cur_num = 11;
		
		//반드시 왼손
		if(cur_num == 1 || cur_num == 4 || cur_num == 7){
			leftY = cur_num / 3;
			leftX = 0;
			answer += "L";
		}
		//반드시 오른손
		else if(cur_num == 3 || cur_num == 6 || cur_num == 9){
			rightY = (cur_num / 3) - 1;
			rightX = 2;
			answer += "R";
		}
		else{
			//누가 더 가까운지 계산
			int leftDistance = (1 - leftX) + abs(leftY - cur_num / 3);
			int rightDistance = (rightX - 1) + abs(rightY - cur_num / 3);

			//둘의 거리가 같다면
			if(leftDistance == rightDistance){
				//왼손잡이면
				if (hand == "left"){
					leftX = 1;
					leftY = cur_num / 3;
					answer += "L";
				}
				else{
					rightX = 1;
					rightY = cur_num / 3;
					answer += "R";
				}
			}
			//거리가 다른 경우
			else{
				if(leftDistance < rightDistance){
					leftX = 1;
					leftY = cur_num / 3;
					answer += "L";
				}
				else{
					rightX = 1;
					rightY = cur_num / 3;
					answer += "R";
				}
			}
		}
	}
	
    return answer;
}