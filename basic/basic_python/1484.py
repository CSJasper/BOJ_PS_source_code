import sys
import math
"""
g = int(sys.stdin.readline())

left = 0
right = 0

square = []
ans = []

MAX_NUM = 200000

for i in range(1,MAX_NUM + 1):
    square.append(i * i)

while True:
    dif = square[right] - square[left]
    if right >= len(square):
        break
    if dif > g:
        left += 1
    if dif < g:
        right += 1
    if dif == g:
        ans.append(math.sqrt(square[right]))
        right += 1

if ans.len == 0:
    print(-1)
else:
    for i in range(len(ans)):
        print(ans[i])

"""
