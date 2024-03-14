import kotlin.math.max

var a = 0
var b = 0
var c = 0

fun insertAndInit() {

}

fun calculate() {
    while (true){
        val input = readln().split(" ").map { it.toInt() }
        a = input[0]; b = input[1]; c = input[2]
        if (a+b+c == 0) break

        val longest = max(a, max(b, c))

        if(input.sum() - longest <= longest){
            println("Invalid")
            continue
        }

        if(a == b && b == c){
            println("Equilateral")
        } else if((a==b && c != a) || (a==c && b != a) || (b == c && a != b)){
            println("Isosceles")
        } else{
            println("Scalene")
        }
    }
}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}