class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        var answer = 1
        
        val hm = HashMap<String, Int>()
        
        clothes.forEach {
            if(hm[it[1]] == null) hm[it[1]] = 1
            else hm[it[1]] = hm[it[1]]!! + 1
        }
        
        hm.forEach{
            println(it.value)
            answer = answer * (it.value + 1)
        }
        
        return answer - 1
    }
}