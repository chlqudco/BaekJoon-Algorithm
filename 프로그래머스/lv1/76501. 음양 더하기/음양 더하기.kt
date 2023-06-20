class Solution {
    fun solution(absolutes: IntArray, signs: BooleanArray): Int {
        var answer: Int = 0
        
        absolutes.forEachIndexed{ idx, value ->
            if(signs[idx]) answer += value
            else answer -= value
        }
        
        return answer
    }
}