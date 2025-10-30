import java.util.*

class Solution {
    fun solution(k: Int, score: IntArray): IntArray {
        var answer: IntArray = intArrayOf()
        
        val pq = PriorityQueue<Int>() { a, b -> b - a }
        
        score.forEach{
            pq.add(it)
            
            val pq2 = PriorityQueue<Int>() { a, b -> a - b }
            
            for(i in 0..(k-1)){
                pq2.add(pq.remove())
                if(pq.isEmpty()) break
            }
            
            answer += pq2.peek()
            
            while(pq2.isNotEmpty()){
                pq.add(pq2.remove())
            }
            
        }
        
        return answer
    }
}