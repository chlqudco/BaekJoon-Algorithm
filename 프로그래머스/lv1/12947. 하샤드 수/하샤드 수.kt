class Solution {
    fun solution(x: Int): Boolean {
        var answer = true
        
        var sum = 0
        var num = x
        while(num > 0){
            sum += (num%10)
            num /= 10
        }
        
        if(x % sum == 0){
            answer = true
        } else {
            answer = false
        }
        
        return answer
    }
}