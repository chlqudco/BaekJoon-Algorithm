class Solution {
    fun solution(sides: IntArray): Int {
        var answer: Int = 0
        
        var maxLength = 0
        var sidesSum = 0
        sides.forEach{ value ->
            sidesSum += value
            if( maxLength < value){
                maxLength = value
            }
        }
        
        answer = if( sidesSum - maxLength > maxLength) 1 else 2
        
        return answer
    }
}