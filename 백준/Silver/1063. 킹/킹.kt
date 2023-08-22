var king = IntArray(2)
var stone = IntArray(2)
var N = 0

fun insertAndInit() {
    val input = readln().split(" ")

    // 세로 범위 : 0 .. 7
    king[0] = input[0][0] - 'A'
    // 가로 범위 : 0 .. 7
    king[1] = input[0][1] - '1'

    stone[0] = input[1][0] - 'A'
    stone[1] = input[1][1] - '1'

    N = input[2].toInt()
}

fun calculate() {
    for (i in 0 until N) {
        when (readln()) {
            "R" -> {
                // 왕이 밖으로 나가는 경우
                if (king[0] == 7) {
                    continue
                }

                // 왕 옆에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[1] == stone[1]) && (king[0] + 1 == stone[0]) && (stone[0] == 7)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[0] += 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[0] += 1
                }

            }

            "L" -> {
                // 왕이 밖으로 나가는 경우
                if (king[0] == 0) {
                    continue
                }

                // 왕 옆에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[1] == stone[1]) && (king[0] - 1 == stone[0]) && (stone[0] == 0)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[0] -= 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[0] -= 1
                }

            }

            "B" -> {
                // 왕이 밖으로 나가는 경우
                if (king[1] == 0) {
                    continue
                }

                // 왕 옆에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[0] == stone[0]) && (king[1] - 1 == stone[1]) && (stone[1] == 0)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[1] -= 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[1] -= 1
                }

            }

            "T" -> {
                // 왕이 밖으로 나가는 경우
                if (king[1] == 7) {
                    continue
                }

                // 왕 옆에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[0] == stone[0]) && (king[1] + 1 == stone[1]) && (stone[1] == 7)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[1] += 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[1] += 1
                }


            }

            "RT" -> {
                // 왕이 밖으로 나가는 경우
                if (king[0] == 7 || king[1] == 7) {
                    continue
                }

                // 왕 대각선에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[1] + 1== stone[1]) && (king[0] + 1 == stone[0]) && (stone[0] == 7 || stone[1] == 7)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[0] += 1
                king[1] += 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[0] += 1
                    stone[1] += 1
                }

            }

            "LT" -> {
                // 왕이 밖으로 나가는 경우
                if (king[0] == 0 || king[1] == 7) {
                    continue
                }

                // 왕 대각선에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[1] + 1== stone[1]) && (king[0] - 1 == stone[0]) && (stone[0] == 0 || stone[1] == 7)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[0] -= 1
                king[1] += 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[0] -= 1
                    stone[1] += 1
                }

            }

            "RB" -> {
                // 왕이 밖으로 나가는 경우
                if (king[0] == 7 || king[1] == 0) {
                    continue
                }

                // 왕 대각선에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[1] - 1== stone[1]) && (king[0] + 1 == stone[0]) && (stone[0] == 7 || stone[1] == 0)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[0] += 1
                king[1] -= 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[0] += 1
                    stone[1] -= 1
                }

            }

            "LB" -> {
                // 왕이 밖으로 나가는 경우
                if (king[0] == 0 || king[1] == 0) {
                    continue
                }

                // 왕 대각선에 돌이 있는데 돌이 가장자리 인 경우
                if ((king[1] - 1== stone[1]) && (king[0] - 1 == stone[0]) && (stone[0] == 0 || stone[1] == 0)) {
                    continue
                }

                // 둘다 아니면 왕 움직여
                king[0] -= 1
                king[1] -= 1

                // 돌이랑 겹치면 돌도 움직여
                if ((king[0] == stone[0]) && (king[1] == stone[1])) {
                    stone[0] -= 1
                    stone[1] -= 1
                }
            }
        }
    }

    println("${'A' + king[0]}${'1' + king[1]}")
    print("${'A' + stone[0]}${'1' + stone[1]}")
}


fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}