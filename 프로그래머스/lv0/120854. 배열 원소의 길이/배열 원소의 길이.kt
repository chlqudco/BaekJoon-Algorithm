class Solution {
    fun solution(strlist: Array<String>): IntArray {
        var answer: IntArray = intArrayOf()
        
        strlist.forEach{ cur -> 
            answer += cur.length
        }
        
        return answer
    }
}