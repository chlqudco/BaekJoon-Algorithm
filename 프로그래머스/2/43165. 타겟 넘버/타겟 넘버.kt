class Solution {
    var answer = 0
    
    fun DFS(idx: Int, numbers: IntArray, target: Int, total: Int){
        
        // base case
        if(numbers.size == idx){
            if(total == target) answer++
            return
        }
        
        // recur case
        DFS(idx + 1, numbers, target, total + numbers[idx])
        DFS(idx + 1, numbers, target, total + numbers[idx] * -1)
    }
    
    fun solution(numbers: IntArray, target: Int): Int {
        
        DFS(1, numbers, target, numbers[0])
        DFS(1, numbers, target, numbers[0] * -1)
        
        return answer
    }
}