import java.util.*

fun bfs(board: Array<IntArray>): Int {
    val n = board.size
    val visited = Array(n) { IntArray(n) { -1 } }
    val queue: Deque<Pair<Int, Int>> = ArrayDeque()
    val dx = listOf(-1, 1, 0, 0)
    val dy = listOf(0, 0, -1, 1)

    queue.addFirst(Pair(0, 0))
    visited[0][0] = 0

    while (queue.isNotEmpty()) {
        val (x, y) = queue.pollFirst()

        for (i in 0..3) {
            val nx = x + dx[i]
            val ny = y + dy[i]

            if (nx in 0 until n && ny in 0 until n) {
                if (visited[nx][ny] == -1) {
                    if (board[nx][ny] == 1) {
                        visited[nx][ny] = visited[x][y]
                        queue.addFirst(Pair(nx, ny))
                    } else {
                        visited[nx][ny] = visited[x][y] + 1
                        queue.addLast(Pair(nx, ny))
                    }
                }
            }
        }
    }
    return visited[n - 1][n - 1]
}

fun main() {
    val n = readLine()!!.toInt()
    val board = Array(n) { readLine()!!.map { it - '0' }.toIntArray() }

    println(bfs(board))
}