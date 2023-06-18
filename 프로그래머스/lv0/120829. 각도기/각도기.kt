class Solution {
    fun solution(angle: Int): Int {
        var answer: Int = 0
        
        answer = when{
            angle < 90 -> 1
            angle == 90 -> 2
            angle < 180 -> 3
            angle == 180 -> 4
            else -> 0
        }
        
        return answer
    }
}