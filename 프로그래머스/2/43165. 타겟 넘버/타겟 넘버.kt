class Solution {
    var answer = 0
    
    fun DFS(arr: IntArray, total:Int, idx:Int, target: Int) {
        if(idx == arr.size){
            if(total == target) answer++
            return
        }
        
        DFS(arr, total + arr[idx], idx+1, target)
        DFS(arr, total - arr[idx], idx+1, target)
    }
    
    fun solution(numbers: IntArray, target: Int): Int {
        
        DFS(numbers, numbers[0], 1, target)
        DFS(numbers, numbers[0] * -1, 1, target)
        
        return answer
    }
}