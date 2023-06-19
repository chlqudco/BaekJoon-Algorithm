class Solution {
    fun solution(n: Long): Long {
        var answer: Long = 0
        
        var arr = mutableListOf<Long>()
        var num = n
        while(num > 0){
            arr.add(num%10)
            num /= 10
        }
        
        arr.sortDescending()
        
        while(arr.isNotEmpty()){
            answer = answer*10 + arr.removeFirst()
        }
        
        return answer
    }
}