import java.util.*

class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        var answer: Int = 0
        
        // 종류별로 귤을 담을 상자 선언 후 같은 종류 끼리 담기
        var Box = IntArray(10000001)
        tangerine.forEach{ value ->
            Box[value]++
        }
        
        // 우선순위 큐에 높은 종류 순서대로 넣기
        var pq = PriorityQueue<Int>() { a, b -> b - a}
        
        for(i in 1..10000000){
            if(Box[i] != 0){
                pq.add(Box[i])
            }
        }
        
        // k개 만큼 뽑기
        var total = 0
        var count = 0
        
        while(pq.isNotEmpty()){
            total += pq.remove()
            count++
            if(total >= k){
                return count 
            }
        }
        
        return answer
    }
}