class Solution {
    
    val visited = BooleanArray(201) { false }
    
    fun BFS(idx: Int, n: Int, computers: Array<IntArray>){
        
        val que = mutableListOf<Int>()
        
        que.add(idx)
        
        while(que.isNotEmpty()){
            val cur = que.removeFirst()
            visited[cur] = true
            
            for(i in 1..n){
                if(i != cur && !visited[i] && computers[cur -1 ][i-1] == 1){
                    que.add(i)
                }
            }
        }
    }
    
    fun solution(n: Int, computers: Array<IntArray>): Int {
        var answer = 0
        
        // for(i in 1..n) visited[i] = true
        
        for(i in 1..n){
            if(!visited[i]){
                BFS(i, n, computers)
                answer++
            }
        }
    
        
        return answer
    }
}