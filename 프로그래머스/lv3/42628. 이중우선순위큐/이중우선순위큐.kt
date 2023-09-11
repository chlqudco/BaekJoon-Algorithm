import java.util.PriorityQueue

class Solution {
fun solution(operations: Array<String>): IntArray {
    var answer = intArrayOf()

    val maxPQ = PriorityQueue<Int>(){ a, b -> b - a}
    val minPQ = PriorityQueue<Int>(){ a, b -> a - b}

    var maxPQCount = 0
    var minPQCount = 0

    operations.forEach { value ->
        val op = value.split(" ")[0]
        val num = value.split(" ")[1].toInt()

        when(op){
            "I" -> {
                maxPQ.add(num)
                minPQ.add(num)
            }
            "D" -> {
                // 최대값 삭제
                if (num == 1){
                    if (maxPQ.isNotEmpty()){
                        maxPQ.remove()
                        minPQCount++
                        if (minPQCount == minPQ.size){
                            minPQ.clear()
                            maxPQ.clear()
                            minPQCount = 0
                            maxPQCount = 0
                        }
                        else if (maxPQ.isEmpty()){
                            minPQ.clear()
                            minPQCount = 0
                            maxPQCount = 0
                        }
                    }
                }else{
                    if (minPQ.isNotEmpty()){
                        minPQ.remove()
                        maxPQCount++
                        if (maxPQCount == maxPQ.size){
                            minPQ.clear()
                            maxPQ.clear()
                            minPQCount = 0
                            maxPQCount = 0
                        }
                        else
                        if (minPQ.isEmpty()){
                            maxPQ.clear()
                            maxPQCount = 0
                            minPQCount = 0
                        }
                    }
                }
            }
        }
    }

    if (maxPQCount >= maxPQ.size || minPQCount >= minPQ.size){
        answer += 0
        answer += 0
        return answer
    }

    if (maxPQ.isNotEmpty()){
        answer += maxPQ.remove()
        answer += minPQ.remove()
    } else{
        answer += 0
        answer += 0
    }

    return answer
}
}