#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
	map<string, int> gem_type;
	int total_gem_type;
	int start = 0, end = 0;
	int gem_length = 9999999;
	answer.push_back(1);
	answer.push_back(1);

	//보석 종류 알아내기
	for (int i = 0; i < gems.size(); i++) gem_type[gems[i]]++;
	total_gem_type = gem_type.size();

	map<string, int> cur_gem;
	cur_gem[gems[0]]++;
	int cur_gem_size = 1;
	while(start <= end){
		if(start == gems.size()) break;
		//1. 모든 보석을 포함하는데 길이도 더 짧은 경우
		if(cur_gem_size == total_gem_type){
			if(gem_length > end - start){
				answer[0] = start + 1;
				answer[1] = end + 1;
				gem_length = end - start;
			}
			//start 한칸 땡기기
			cur_gem[gems[start]]--;
			if(cur_gem[gems[start]] == 0) cur_gem_size--;
			start++;
		}
		//모든 보석을 포함하지 않으면 end를 댕겨야지
		else{
			end++;
			if(end == gems.size()) break;
			cur_gem[gems[end]]++;
			if(cur_gem[gems[end]]==1) cur_gem_size++;
		}
	}
    return answer;
}