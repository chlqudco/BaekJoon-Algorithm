class Solution {
    val dp = LongArray(2001) { 0 }
    
    fun solution(n: Int): Long {
        
        dp[1] = 1L
        dp[2] = 2L
        dp[3] = 3L
        dp[4] = 5L
        
        for(i in 5..n){
            dp[i] = (dp[i-1] + dp[i-2]) % 1234567
        }
        
        return dp[n]
    }
}