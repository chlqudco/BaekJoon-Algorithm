class Solution {
    fun solution(s1: Array<String>, s2: Array<String>): Int {
        var answer: Int = 0
        
        s1.forEach{ value -> 
            if( s2.contains(value) ) answer++
        }
        
        return answer
    }
}