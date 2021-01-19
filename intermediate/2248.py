
##2248번 문제 코드 with python3

# N(1 <= N <= 31)자리의 이진수가 있다. 이러한 이진수 중에서, L (1 <= L <= N)
# 개 이하의 비트만 1인 것을 크기 순으로 나열했을 때, I번째로 나오는 이진수를 구해내는
# 프로그램을 작성해야 한다. 이진수는 0으로 시작할 수도 있다.

import sys

MAX_STR_LENGTH = 33

dp = [ [0] * MAX_STR_LENGTH for i in range(MAX_STR_LENGTH)]
def update_str(n, l, i, str) :
    # 만약 이진수의 길이가 0이라면 str을 업데이트 할 필요가 없이 걍 종료
    if n == 0 :
        return
    if l == 0 :



# sys.stdin.readline().split()이 iterable한 객체를 반환하므로 이런식의 등식이 성립한다.
N, L, I = map(int,sys.stdin.readline().split())

str = ''