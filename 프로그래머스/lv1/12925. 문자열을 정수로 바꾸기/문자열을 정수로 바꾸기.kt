class Solution {
    fun solution(s: String): Int {
        var answer = 0
        
        if(s[0] == '+'){
            answer = s.substring(1, s.length).toInt()
        } else if(s[0] == '-'){
            answer = s.substring(1, s.length).toInt() * -1
        } else{
            answer = s.toInt()
        }
        
        return answer
    }
}