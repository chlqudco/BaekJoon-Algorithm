#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    for (int i = 0; i < numbers.size(); i++) answer += numbers[i];
	
    return 44 - answer;
}