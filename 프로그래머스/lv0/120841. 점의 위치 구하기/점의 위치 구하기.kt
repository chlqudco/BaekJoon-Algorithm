class Solution {
    fun solution(dot: IntArray): Int {
        var answer: Int = 0
        
        answer = when{
            dot[0] > 0 && dot[1] > 0 -> 1
            dot[0] < 0 && dot[1] > 0 -> 2
            dot[0] < 0 && dot[1] < 0 -> 3
            else -> 4
        }
        
        return answer
    }
}