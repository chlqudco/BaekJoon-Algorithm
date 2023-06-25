import kotlin.math.*

class Solution {
    fun solution(s: String): String {
        var answer = ""
        
        var numList = s.split(" ").map { it.toInt() }
        var maxNum = numList[0]
        var minNum = numList[0]
        
        numList.forEach { value ->
            maxNum = max(maxNum, value)
            minNum = min(minNum, value)
        }

        answer = "$minNum $maxNum"
        
        return answer
    }
}