import java.util.LinkedList

var T = 0

var w = 0
var h = 0

// 상근이
var sangY = 0
var sangX = 0

// 방향
val dx = intArrayOf(1, -1, 0, 0)
val dy = intArrayOf(0, 0, 1, -1)

fun insertAndInit() {
    T = readln().toInt()
}

fun bfs(fire: LinkedList<Pair<Int, Int>>, map: Array<CharArray>): Int {
    val visited = Array(1001){ BooleanArray(1001) { false } }
    val que = LinkedList<Pair<Int, Int>>()

    visited[sangY][sangX] = true
    que.add(Pair(sangY, sangX))

    var second = 0

    while (que.isNotEmpty()){
        // 불 먼저 옮겨붙기
        val fireSize = fire.size
        for (i in 0 until fireSize){
            val curFire = fire.removeFirst()
            repeat(4){ it ->
                val nextY = curFire.first + dy[it]
                val nextX = curFire.second + dx[it]

                if(CanGoFire(nextY, nextX, map)){
                    map[nextY][nextX] = '*'
                    fire.add(Pair(nextY, nextX))
                }
            }
        }

        // 현재 있는 상근이 다 꺼내
        val size = que.size
        for (i in 0 until size){
            val cur = que.removeFirst()

            // 벽에 도착했으면 탈출
            if (cur.first == 0 || cur.first == h-1 || cur.second == 0 || cur.second == w-1){
                return second + 1
            }

            // 아니면 옮겨
            repeat(4){ it ->
                val nextY = cur.first + dy[it]
                val nextX = cur.second + dx[it]

                if (CanGo(nextY, nextX, map, visited)){
                    visited[nextY][nextX] = true
                    que.add(Pair(nextY, nextX))
                }
            }

        }
        second++
    }

    // 불가능한 경우
    return -1
}

fun CanGo(nextY: Int, nextX: Int, map: Array<CharArray>, visited: Array<BooleanArray>): Boolean {
    return nextY in 0 until h && nextX < w && nextX >= 0 && !visited[nextY][nextX] && map[nextY][nextX] == '.'
}


fun CanGoFire(nextY: Int, nextX: Int, map: Array<CharArray>): Boolean {
    return nextY in 0 until h && nextX < w && nextX >= 0 && (map[nextY][nextX] != '#' && map[nextY][nextX] != '*')
}

fun calculate() {
    repeat(T){
        // 불
        val fire = LinkedList<Pair<Int, Int>>()
        // 지도
        val map = Array(1001){ CharArray(1001) }

        // 정보 입력
        val input = readln().split(" ").map { it.toInt() }
        w = input[0]; h = input[1]

        repeat(h){ j ->
            val line = readln()
            line.forEachIndexed{ idx , value ->
                map[j][idx] = value
                // 불 저장
                if (value == '*'){
                    fire.add(Pair(j, idx))
                }
                // 상근이 저장
                if( value == '@'){
                    sangY = j
                    sangX = idx
                }
            }
        }

        // BFS 실행
        val result = bfs(fire, map)
        if (result == -1){
            println("IMPOSSIBLE")
        } else{
            println(result)
        }


    }
}


fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}