class Solution {
    
    // 유니온 파인드 용 배열
    val parent = IntArray(101) { it }
    
    fun node_union(node1 : Int, node2 : Int){
        if(node_find(node1) != node_find(node2)){
            parent[node_find(node2)] = node_find(node1)
        }
    }
    
    fun node_find(node: Int) : Int{
        if(parent[node] == node) return node
        
        parent[node] = node_find(parent[node])
        return parent[node]
    }

    fun isLinked(start : Int, end : Int): Boolean = node_find(start) == node_find(end)
    
    
    fun solution(n: Int, costs: Array<IntArray>): Int {
        var answer = 0
        
        // 가중치 오름차순 정렬
        val pq2 = costs.sortedBy { it[2] }
        
        // 작은 가중치부터 보면서
        pq2.forEach{ value ->
            // 두 정점이 연결되어 있지 않으면
            if(!isLinked(value[0], value[1])){
                // 해당 간선 포함
                answer += value[2]
                
                // 두 정점 연결
                node_union(value[0], value[1])
            }
        }
        
        
        return answer
    }
}