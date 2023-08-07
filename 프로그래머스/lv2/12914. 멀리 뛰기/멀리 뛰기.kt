class Solution {
    fun solution(n: Int): Long {
        var answer: Long = 0
        
        var dp = LongArray(2001)
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3
        dp[4] = 5
        for(i in 5 .. 2000){
            dp[i] = (dp[i-1] + dp[i-2]) % 1234567
        }
        
        return dp[n]
    }
}