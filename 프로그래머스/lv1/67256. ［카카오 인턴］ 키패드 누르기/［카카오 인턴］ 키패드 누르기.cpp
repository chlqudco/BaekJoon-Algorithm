#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
typedef pair<int, int> p;

string solution(vector<int> numbers, string hand) {
	p rightHand = { 3,2 };
	p leftHang = { 3,0 };

	bool isRightHand = false;
	string answer = "";

	if (hand == "right") isRightHand = true;

	int numbers_size = numbers.size();
	for (int i = 0; i < numbers_size; i++){
		int curNum = numbers[i];
		if (curNum == 1 || curNum == 4 || curNum == 7) {
			answer += "L";
			leftHang = { curNum / 3 ,0 };
		}
		else if (curNum == 3 || curNum == 6 || curNum == 9) {
			answer += "R";
			rightHand = { curNum / 3 - 1 ,2 };
		}
		else {
			int dist_r = 0;
			int dist_l = 0;

			if (curNum == 2) {
				dist_l = abs(leftHang.first - 0) + abs(1 - leftHang.second);
				dist_r = abs(rightHand.first - 0) + abs(1 - rightHand.second);
				if (dist_l == dist_r) {
					if (isRightHand) {
						answer += "R";
						rightHand = { curNum / 3 ,1 };
					}
					else {
						answer += "L";
						leftHang = { curNum / 3 ,1 };
					}
				}
				else if (dist_l > dist_r) {
					answer += "R";
					rightHand = { curNum / 3 ,1 };
				}
				else {
					answer += "L";
					leftHang = { curNum / 3 ,1 };
				}
			}
			else if(curNum == 5) {
				dist_l = abs(leftHang.first - 1) + abs(1 - leftHang.second);
				dist_r = abs(rightHand.first - 1) + abs(1 - rightHand.second);
				if (dist_l == dist_r) {
					if (isRightHand) {
						answer += "R";
						rightHand = { curNum / 3 ,1 };
					}
					else {
						answer += "L";
						leftHang = { curNum / 3 ,1 };
					}
				}
				else if (dist_l > dist_r) {
					answer += "R";
					rightHand = { curNum / 3 ,1 };
				}
				else {
					answer += "L";
					leftHang = { curNum / 3 ,1 };
				}
			}
			else if (curNum == 8) {
				dist_l = abs(leftHang.first - 2) + abs(1 - leftHang.second);
				dist_r = abs(rightHand.first - 2) + abs(1 - rightHand.second);
				if (dist_l == dist_r) {
					if (isRightHand) {
						answer += "R";
						rightHand = { curNum / 3 ,1 };
					}
					else {
						answer += "L";
						leftHang = { curNum / 3 ,1 };
					}
				}
				else if (dist_l > dist_r) {
					answer += "R";
					rightHand = { curNum / 3 ,1 };
				}
				else {
					answer += "L";
					leftHang = { curNum / 3 ,1 };
				}
			}
			else {
				dist_l = abs(leftHang.first - 3) + abs(1 - leftHang.second);
				dist_r = abs(rightHand.first - 3) + abs(1 - rightHand.second);
				if (dist_l == dist_r) {
					if (isRightHand) {
						answer += "R";
						rightHand = { 3 ,1 };
					}
					else {
						answer += "L";
						leftHang = {3 ,1 };
					}
				}
				else if (dist_l > dist_r) {
					answer += "R";
					rightHand = { 3 ,1 };
				}
				else {
					answer += "L";
					leftHang = { 3 ,1 };
				}
			}
		}
	}
	return answer;
}