class Solution {
    fun solution(n: Long): Long {
        
        for(i in 1..30000000){
            if(i.toLong() * i.toLong() == n) return (i+1).toLong()*(i+1).toLong()
            
        }
        
        return -1
    }
}