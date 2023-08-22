class Solution {
    fun solution(n: Int): Int {
        var answer = 0
        
        val fibo = LongArray(100001)
        
        fibo[0] = 0L
        fibo[1] = 1L
        
        for(i in 2 .. 100000){
            fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567L
        }
        
        return (fibo[n] % 1234567L).toInt()
    }
}