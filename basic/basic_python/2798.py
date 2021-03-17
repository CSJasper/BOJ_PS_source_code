import sys

card_num, upper_bound = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

min_dist = 300000
candidate = ()

for i in range(len(nums)):
    first = nums[i]
    for j in range(i + 1, len(nums)):
        second = nums[j]
        for k in range(j + 1, len(nums)):
            third = nums[k]
            candidate = (first, second, third)
            if sum(candidate) > upper_bound:
                continue
            if min_dist > upper_bound - sum(candidate):
                min_dist = upper_bound - sum(candidate)

print(upper_bound - min_dist)
