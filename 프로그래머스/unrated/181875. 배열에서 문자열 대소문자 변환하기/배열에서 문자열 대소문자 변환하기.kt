class Solution {
    fun solution(strArr: Array<String>): Array<String> {
        var answer: Array<String> = arrayOf<String>()
        
        strArr.forEachIndexed { idx, value ->
            // 짝수는 소문자
            if(idx % 2 == 0){
                answer += value.lowercase()
            }
            // 홀수는 대문자
            else{
                answer += value.uppercase()
            }
        }
        
        return answer
    }
}