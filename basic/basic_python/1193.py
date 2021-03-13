import sys

order = int(sys.stdin.readline())

# 몇번째 군에 있는지 알아내야 한다.
# 홀수 군인지 짝수 군인지도 영향을 미친다
# 홀수 군이면 아래에서 위로 짝수 군이면 위에서 아래로 훑는다
# 현재 군일 때, 이전 군까지의 원소의 개수의 합이 필요하다.
# 현재 i번째 군일 때 이전 군까지의 원소의 개수의 합을 구해야 한다.

count = 1

while count <= order:
    if count is order:
        break
    else:

