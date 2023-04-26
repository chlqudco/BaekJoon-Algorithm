import java.util.Stack

var S = ""
val st = Stack<Char>()

fun insertAndInit() {
    S = readln()
}

fun printAllStack(){
    if (st.isNotEmpty()){
        while (st.isNotEmpty()){
            print(st.pop())
        }
    }
}

fun calculate() {
    var isSign = false

    S.forEach {
        when(it){
            '<' -> {
                printAllStack()
                print('<')
                isSign = true
            }
            '>' -> {
                isSign = false
                print('>')
            }
            ' ' -> {
                printAllStack()
                print(" ")
            }
            else -> {
                if (!isSign){
                    st.add(it)
                } else{
                    print(it)
                }
            }
        }
    }
    printAllStack()
}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}