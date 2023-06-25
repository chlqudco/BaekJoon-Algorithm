class Solution {
    fun solution(s: String): String {
        var answer = ""
        
        // 문자열 분리
        var strList = s.split(" ")
        
        // 첫문자 대문자, 나머지 소문자로
        strList.forEach{ value1 ->
            var tmpStr = ""
            
            value1.forEachIndexed{ idx, value ->
                // 첫 문자인 경우
                if(idx == 0){
                    // 소문자인 경우
                    if(value >= 'a' && value <= 'z'){
                        tmpStr += "${value - 32}"
                    } else {
                        tmpStr += "${value}"
                    }
                 }
                // 둘 째 문자인 경우
                else {
                    // 대문자인 경우
                    if(value >= 'A' && value <= 'Z'){
                        tmpStr += "${value + 32}"
                    } else {
                        tmpStr += "${value}"
                    }
                }
            }
            answer += "$tmpStr "
            
        }
        
        return answer.dropLast(1)
    }
}