import java.util.PriorityQueue

class Solution {
    fun solution(s: String): IntArray {
    var answer = intArrayOf()

    // 숫자 꺼내기
    val numCount = IntArray(1000001)
    var numStr = ""
    s.forEach { value ->
        // 숫자인 경우 이어
        if (value in '0'..'9'){
            numStr += value
        }
        // 끝나는 그거면 넣어
        if ((value == ',' || value == '}') && numStr.isNotEmpty()){
            numCount[numStr.toInt()]++
            numStr = ""
        }
    }
    
    // 우선순위 큐에 담기
    val pq = PriorityQueue<Pair<Int, Int>>(){ a, b -> b.second - a.second}
    repeat(1000001){
        if (numCount[it] != 0){
            pq.add(Pair(it, numCount[it]))
        }
    }
    
    while (pq.isNotEmpty()){
        answer += pq.remove().first
    }
    
    return answer
    }
}