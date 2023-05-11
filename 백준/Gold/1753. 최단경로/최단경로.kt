import java.util.PriorityQueue
import kotlin.math.min

var V = 0
var E = 0
var K = 0

// 다익스트라
const val INF = 987654321
val graph = Array(20001) { mutableListOf<Node>() }
val cost = IntArray(20001) { INF }

data class Node(
    val idx: Int,
    val weight : Int
)

fun insertAndInit() {

    val input = readln().split(" ").map { it.toInt() }
    V = input[0]; E = input[1]
    K = readln().toInt()

    // 간선 입력
    repeat(E) {
        val (u, v, w) = readln().split(" ").map { it.toInt() }
        graph[u].add(Node(v, w))
    }

    cost[K] = 0
}

fun dijkstra() {

    // 우선순위 큐
    val pq = PriorityQueue<Node> { a, b ->
         a.weight - b.weight
    }

    // 자기 자신은 거리 0
    pq.add(Node(K, 0))

    // 큐가 빌때까지
    while (!pq.isEmpty()) {

        // 거리가 제일 가까운 노드 하나 꺼내기
        val curNode = pq.remove()

        // 알아보기 쉽게 거리와 노드 번호 분리
        val dist = curNode.weight
        val idx = curNode.idx

        // 현재 뽑은 거리가 최단경로가 아니면 다음 간선 보기
        if (dist > cost[idx]) continue

        // 현재 노드에 연결된 선분을 조회하며
        graph[idx].forEachIndexed { index, value ->

            // 상대방 노드
            val nextIdx = value.idx

            // idx를 경유하는 상대방까지의 거리
            val nextDist = dist + value.weight

            // 최단경로면 갱신
            if (cost[nextIdx] > nextDist) {
                cost[nextIdx] = nextDist
                pq.add(Node(nextIdx, nextDist))
            }
        }
    }

}

fun calculate() {

    // 다익스트라 실행
    dijkstra()

    // 최단 경로 출력
    repeat(V) {
        if (cost[it + 1] == INF) {
            println("INF")
        } else {
            println(cost[it + 1])
        }
    }
}


fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}