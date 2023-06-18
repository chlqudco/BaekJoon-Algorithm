class Solution {
    fun solution(numbers: IntArray): Int {
        var answer: Int = 0
        
        numbers.sort()
        
        answer = numbers[numbers.size - 1] * numbers[numbers.size - 2]
        
        return answer
    }
}