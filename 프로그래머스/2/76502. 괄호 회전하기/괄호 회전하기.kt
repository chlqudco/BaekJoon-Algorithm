import java.util.*

class Solution {
    
    fun checkStr(str : String): Boolean{
        val st = Stack<Char>()
        
        str.forEach{
            if(it == '[' || it == '{' || it == '('){
                st.push(it)
            } else {
                if(st.isEmpty()) return false
                
                if(it == ']' && st.peek()=='['){
                    st.pop()
                } else if(it == '}' && st.peek()=='{'){
                    st.pop()
                } else if(it == ')' && st.peek()=='('){
                    st.pop()
                }  
            }
        }
        return st.isEmpty() 
    }
    
    fun solution(s: String): Int {
        var answer: Int = 0
        
        var newStr = s
        
        // 한칸씩 회전
        repeat(s.length){
            newStr = newStr[newStr.length-1] + newStr.substring(0, newStr.length - 1)
            // 괄호 검사
            if(checkStr(newStr)) answer++
        }
        
        return answer
    }
}