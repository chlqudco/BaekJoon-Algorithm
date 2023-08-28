import java.util.*

data class Node(
    val genre: String,
    val count: Int
)

data class Node2(
    val idx: Int,
    val value: Int
)

class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        var answer = intArrayOf()
        
        // 최대 장르? 찾아보자
        val genreMap = mutableMapOf<String,Int>()
        
        genres.forEachIndexed{ idx, value ->
            if(genreMap.containsKey(value)){
                genreMap.put(value, genreMap[value]!! + plays[idx])
            }
            else{
                genreMap[value] = plays[idx]
            } 
        }
        
        // 우선순위 큐로 많이 재생된 장르 가르기
        val genrePQ = PriorityQueue<Node> { a, b -> b.count - a.count}
        
        genreMap.keys.forEach { value ->
            genrePQ.add(Node(value, genreMap[value]!!))
        }
        
        // 하나의 장르씩 꺼낸 뒤 결과에 담기
        while(genrePQ.isNotEmpty()){
            val curGenre = genrePQ.remove()
            
            // 이 장르에서 가장 유명한거 2개 찾기
            val curGenrePQ = PriorityQueue<Node2> { a, b -> b.value - a.value }
            
            // 일단 다 집어넣고
            genres.forEachIndexed{ idx, value -> 
                if(value == curGenre.genre){
                    curGenrePQ.add(Node2(idx, plays[idx]))
                }
            }
            
            // 2개 빼기
            answer += curGenrePQ.remove().idx
            if(curGenrePQ.isNotEmpty()) answer += curGenrePQ.remove().idx
        }
        
        
        return answer
    }
}