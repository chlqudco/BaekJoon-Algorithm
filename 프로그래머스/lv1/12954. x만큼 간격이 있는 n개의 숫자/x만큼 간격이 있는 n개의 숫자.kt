class Solution {
    fun solution(x: Int, n: Int): LongArray {
        var answer = longArrayOf()
        
        var start = x.toLong()
        
        repeat(n){
            answer += start
            start += x.toLong()
        }
        
        return answer
    }
}