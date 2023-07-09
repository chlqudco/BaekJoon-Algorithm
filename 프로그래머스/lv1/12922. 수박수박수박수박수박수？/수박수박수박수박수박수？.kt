class Solution {
    fun solution(n: Int): String {
        var answer = ""
        
        repeat(n){ idx ->
            if(idx % 2 == 0){
                answer += "수"
            } else {
                answer += "박"
            }
        }
        
        return answer
    }
}