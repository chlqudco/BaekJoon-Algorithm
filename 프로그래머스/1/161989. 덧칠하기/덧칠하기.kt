class Solution {
    fun solution(n: Int, m: Int, section: IntArray): Int {
        var answer: Int = 0
        
        var wallArr = BooleanArray(n+m+1) { true }
        
        section.forEach{
            wallArr[it] = false
        }
        
        for(i in 1..n){
            if(!wallArr[i]){
                answer++
                repeat(m){
                    wallArr[i+it] = true
                }
            }
        }
        
        return answer
    }
}