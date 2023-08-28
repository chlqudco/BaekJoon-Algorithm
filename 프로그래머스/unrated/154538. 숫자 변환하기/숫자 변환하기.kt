import java.util.*

class Solution {

    fun bfs(x: Int, y: Int, n: Int): Int{
    val visited = mutableSetOf<Int>()
    val queue: Queue<Pair<Int, Int>> = LinkedList()

    queue.offer(Pair(x, 0))

    while (queue.isNotEmpty()) {
        val (curr, count) = queue.poll()

        if (curr == y) return count

        listOf(curr + n, curr * 2, curr * 3).forEach { nextVal ->
            if (nextVal !in visited && nextVal <= y) {
                visited.add(nextVal)
                queue.offer(Pair(nextVal, count + 1))
            }
        }
    }

    return -1
    }

    fun solution(x: Int, y: Int, n: Int): Int {
        var answer: Int = bfs(x, y, n)
        
        return answer
    }
}