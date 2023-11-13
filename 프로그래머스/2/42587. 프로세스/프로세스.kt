import java.util.*

class Solution {
    
    data class Node(
        val idx: Int,
        val value: Int
    )
    
    fun solution(priorities: IntArray, location: Int): Int {
        var answer = 0
        
        val que = mutableListOf<Node>()
        val maxPQ = PriorityQueue<Int>{ a, b -> b - a}
        
        priorities.forEachIndexed{ idx, value ->
            que.add(Node(idx, value))
            maxPQ.add(value)
        }
        
        while(true){
            val cur = que.removeFirst()
            // 정답
            if(maxPQ.peek() == cur.value && cur.idx == location){
                return answer + 1
            }
            // 지금 뽑아야 되는 경우
            if(maxPQ.peek() == cur.value){
                answer++
                maxPQ.remove()
            }
            else{
                que.add(cur)
            }
        }
        
        return answer
    }
}