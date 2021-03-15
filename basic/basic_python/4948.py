import sys

nums = []

while True:
    num = int(sys.stdin.readline())
    if num == 0:
        break
    nums.append(num)

maximum_num = max(nums)

prime = [True for i in range(2 * maximum_num + 1)]
prime[0] = False
prime[1] = False

for i in range(2, 2 * maximum_num + 1):
    if prime[i] is True:
        for j in range(i * i, 2 * maximum_num + 1, i):
            prime[j] = False

for start in nums:
    end = start * 2
    start += 1
    count = 0
    for i in range(start, end + 1):
        if prime[i] is True:
            count += 1
    print(count)
