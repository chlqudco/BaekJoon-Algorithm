class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 0
        
        for(i in 2 .. n){
            if(n % i == 1) return i
        }
        return 0
    }
}