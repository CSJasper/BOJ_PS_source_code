import sys

MAX_NUM = 8
nums = [0 for i in range(MAX_NUM)]


# 이것도 순열을 한칸 한칸씩 채운다.
def print_permutation(permutation_index, max_num, length):
    if permutation_index == length:
        for i in range(length):
            print(nums[i], end=' ')
        print('\n', end='')
        return
    for i in range(1, max_num + 1):
        if permutation_index == 0:
            nums[permutation_index] = i
        else:
            if nums[permutation_index - 1] <= i:
                nums[permutation_index] = i
            else:
                continue
        print_permutation(permutation_index + 1, max_num, length)


num_range, num_count = map(int, sys.stdin.readline().split())

print_permutation(0, num_range, num_count)
