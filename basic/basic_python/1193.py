import sys

order = int(sys.stdin.readline())

# 몇번째 군에 있는지 알아내야 한다.
# 홀수 군인지 짝수 군인지도 영향을 미친다
# 홀수 군이면 아래에서 위로 짝수 군이면 위에서 아래로 훑는다
# 현재 군일 때, 이전 군까지의 원소의 개수의 합이 필요하다.
# 현재 i번째 군일 때 이전 군까지의 원소의 개수의 합을 구해야 한다.

# 전략 :
# order 번째 수를 찾아야 한다.
# i군의 j번째 원소 : i가 홀수이면 i - (j - 1) / j 가 된다. i 가 짝수이면 j / i - (j - 1)
# i군에 속하는 원소인지 확인한다 -> 현재 군까지의 원소의 개수를 세어 봤을 때, 그 개수 이하라면 그 군에 속한 수가 된다.
# 만약 i번째 군에 속하는지 알았다면 (i-1)번째 군 까지의 원소의 개수를 현재 숫자에서 뺀다 그게 jth 번째 수가 된다.

currentGroup = 1  # 처음에는 1 군이다.
currentGroupSum = (currentGroup * (currentGroup + 1)) // 2

while order > currentGroupSum:
    currentGroup += 1
    currentGroupSum = (currentGroup * (currentGroup + 1)) // 2

if currentGroup == 1:
    print('1/1')
    sys.exit(0)

i = currentGroup
beforeGroupSum = ((currentGroup - 1) * currentGroup) // 2
j = order - beforeGroupSum

if i % 2 == 0:  # i 가 짝수이면
    upper = j
    lower = i - (j - 1)
else:
    upper = i - (j - 1)
    lower = j

print(f'{upper}/{lower}')
