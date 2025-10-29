class Solution {
    fun solution(s: String): String {
        var answer = ""
        
        var arr = s.split(" ").map{ it.toInt() }.toIntArray().sorted()
        
        answer = "${arr[0]} ${arr.last()}"
        
        return answer
    }
}