import sys

MAX_NUM = 1000000000

num = int(sys.stdin.readline())

accSum = 1
idx = 0

for i in range(1, num + 1):
    idx = i
    accSum += (i - 1) * 6
    if num <= accSum:
        break

print(idx)