class Solution {
    fun solution(n: Long): IntArray {
        var answer = intArrayOf()
        
        var num = n
        while(num > 0){
            answer += (num % 10).toInt()
            num /= 10
        }
        
        return answer
    }
}