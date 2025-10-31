class Solution {
    fun solution(n: Int): Int {
        val dp = IntArray(100001) { 0 }
        
        dp[1] = 1
        dp[2] = 1
        for(i in 3..n){
            dp[i] = (dp[i-1] + dp[i-2]) % 1234567
        }
        
        return dp[n]
    }
}