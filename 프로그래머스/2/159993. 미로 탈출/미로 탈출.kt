class Solution {
    data class Node(val y :Int, val x :Int)
    
    var isLeverCheck = false
    
    fun BFS(x: Int, y: Int, leverX: Int, leverY: Int, endX: Int, endY: Int, maps: Array<String>) : Int{
        val visited = Array(101) { IntArray(101) { 0 } }
        val dx = intArrayOf(1, -1, 0, 0)
        val dy = intArrayOf(0, 0, 1, -1)
        val pq = mutableListOf<Node>()
        
        var startX = 0
        var startY = 0
        
        if(!isLeverCheck){
            startY = y
            startX = x
        } else {
            startY = leverY
            startX = leverX
        }
        
        visited[startY][startX] = 1
        pq.add(Node(startY, startX))
        
        while(pq.isNotEmpty()){
            val cur = pq.removeFirst()
            
            // 레버 땡겨야 되는 경우
            if(!isLeverCheck && cur.y == leverY && cur.x == leverX){
                isLeverCheck = true
                return visited[cur.y][cur.x]
            }
            
            // 레버 당기고 도착지에 도착한 경우
            if(isLeverCheck && cur.y == endY && cur.x == endX){
                return visited[cur.y][cur.x]
            }
            
            repeat(4){
                val nextY = cur.y + dy[it]
                val nextX = cur.x + dx[it]
                
                if(nextY >= 0 && nextX >= 0 && nextY < maps.size && nextX < maps[0].length && maps[nextY][nextX] != 'X' && visited[nextY][nextX] == 0){
                    visited[nextY][nextX] = visited[cur.y][cur.x] + 1
                    pq.add(Node(nextY, nextX))
                }
            }
            
        }
        
        return -1
    }
    
    fun solution(maps: Array<String>): Int {
        var answer: Int = 0
        
        var startX = 0
        var startY = 0
        
        var leverX = 0
        var leverY = 0
        
        var endX = 0
        var endY = 0
        
        // 좌표 구하기
        for(i in 0 until maps.size){
            for(j in 0 until maps[i].length){
                if(maps[i][j] == 'S'){
                    startY = i
                    startX = j
                }
                else if(maps[i][j] == 'E'){
                    endX = j
                    endY = i
                } else if(maps[i][j] == 'L'){
                    leverY = i
                    leverX = j
                }
            }
        }
        
        // start 부터 lever 까지 이동
        
        val leverDistance = BFS(startX, startY, leverX, leverY, endX, endY, maps)
        if(leverDistance == -1) return -1
        
        // lever 부터 end 까지 이동
        val endDistance = BFS(startX, startY, leverX, leverY, endX, endY, maps)
        if(endDistance == -1) return -1
        
        return leverDistance + endDistance - 2
    }
}