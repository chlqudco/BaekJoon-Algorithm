import kotlin.math.*

class Solution {
    fun solution(arr: IntArray): IntArray {
        var answer = intArrayOf()
        
        // 작은 수 찾기
        var minNum = arr[0]
        arr.forEachIndexed{idx, value ->
            minNum = min(minNum, value)
        }
        
        arr.forEach{ value -> 
            if(value != minNum){
                answer += value
            }
        }
        
        if(answer.isEmpty()){
            answer += -1
        }
        
        return answer
    }
}