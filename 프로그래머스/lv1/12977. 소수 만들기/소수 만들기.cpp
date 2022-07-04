#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

bool isPrimeNumber(int x) {
	// 2부터 x의 제곱근까지의 모든 수를 확인하며
	for (int i = 2; i <= (int)sqrt(x); i++) {
		// x가 해당 수로 나누어떨어진다면
		if (x % i == 0) {
			return false; // 소수가 아님
		}
	}
	return true; // 소수임
}


int solution(vector<int> nums) {
	int answer = 0;

	int nums_size = nums.size();
	for (int i = 0; i < nums_size; i++) {
		for (int j = i+1; j < nums_size; j++){
			for (int k = j+1; k < nums_size; k++){
				if (isPrimeNumber(nums[i] + nums[j] + nums[k])) answer++;
			}
		}
	}

	return answer;
}