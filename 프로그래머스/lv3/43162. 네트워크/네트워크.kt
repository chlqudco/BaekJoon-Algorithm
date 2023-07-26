class Solution {
    
    val graph = Array(201) { IntArray(201) }
    val visited = BooleanArray(201)
    
    fun BFS(idx : Int, n : Int){
        visited[idx] = true
        val queue = mutableListOf<Int>()
        queue.add(idx)
        
        while(queue.isNotEmpty()){
            val cur = queue.removeFirst()
            
            repeat(n){ idx2 ->
                if(cur != idx2 && !visited[idx2] && graph[cur][idx2] == 1){
                    queue.add(idx2)
                    visited[idx2] = true
                }
            }
        }
    }
    
    fun solution(n: Int, computers: Array<IntArray>): Int {
        var answer = 0
        
        
        computers.forEachIndexed{ y, arr -> 
            arr.forEachIndexed{ x, value ->
                graph[y][x] = value
            }
        }
        
        repeat(n){ idx ->
            if(!visited[idx]){
                BFS(idx, n)
                answer++
            }
        }
        
        return answer
    }
}