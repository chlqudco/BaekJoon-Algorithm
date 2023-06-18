class Solution {
    fun solution(num_list: IntArray): IntArray {
        var answer: IntArray = intArrayOf()
        
        answer += num_list.count{ it % 2 == 0}
        answer += num_list.count{ it % 2 == 1}
        
        return answer
    }
}