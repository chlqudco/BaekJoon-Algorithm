import java.util.*

class Solution {
    fun solution(begin: String, target: String, words: Array<String>): Int {
        var answer = 1
        val word_length = begin.length
        
        //BFS 돌리기
        val queue : Queue<String> = LinkedList()
        val visited = BooleanArray(words.size) { false }
        
        queue.add(begin)
        
        while(queue.isNotEmpty()){
            
            // 큐에 있는거 다 꺼내야 함
            val size = queue.size
            for(i in 0 until size){
                // 현재 단어 꺼내기
                val cur = queue.remove()
                
                // 완성이면 탈출
                if(cur == target){
                    return answer - 1
                }
                
                // 모든 원소 돌면서 길이가 1인거 찾기
                words.forEachIndexed{ idx, value -> 
                    if(!visited[idx]){
                        var differ = 0
                        for(i in 0 until word_length){
                            if(cur[i] != value[i]){
                                differ++
                            }
                        }
                        if(differ == 1){
                            visited[idx] = true
                            queue.add(value)
                        }
                    }
                }
            }
            
            answer++
        }
        
        return 0
    }
}