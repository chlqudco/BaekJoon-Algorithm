class Solution {
    fun solution(n: Int, t: Int): Int {
        var answer: Int = n
        
        repeat(t){
            answer *= 2
        }
        
        return answer
    }
}