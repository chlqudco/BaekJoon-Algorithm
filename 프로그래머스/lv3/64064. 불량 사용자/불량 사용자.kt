class Solution {    
    val visitedSet = mutableSetOf<String>()
  
    fun solution(user_id: Array<String>, banned_id: Array<String>): Int {
        dfs(0, banned_id.size, IntArray(user_id.size), user_id, banned_id)     
        return visitedSet.size
    }
    
    fun dfs(depth: Int, target: Int, visited: IntArray, user_id: Array<String>, banned_id: Array<String>) {
        if (depth == target) {
            visitedSet.add(visited.contentToString())
            return
        }
        
        for (i in user_id.indices) {
            if (visited[i] == 0 && check(user_id[i], banned_id[depth])) {
                visited[i] = 1
                dfs(depth + 1, target, visited, user_id, banned_id)
                visited[i] = 0
            }
        }
    }
    
    fun check(user: String, banned: String): Boolean {
        if (user.length != banned.length)
            return false
        
        for (i in 0 until user.length) {
            if (banned[i] != '*' && user[i] != banned[i])
                return false
        }
        return true
    }
}