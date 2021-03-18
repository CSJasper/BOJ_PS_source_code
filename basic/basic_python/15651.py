import sys

MAX_LENGTH = 7
nums = [0 for i in range(MAX_LENGTH)]


# 순열을 하나씩 만들고 완전히 순열이 만들어지면 그 순열을 출력한다.
# 순열의 인덱스를 받고 한칸 한칸 채워나간다.
def print_permutation(permutation_index, num_max, length):

    if permutation_index == length:
        for i in range(length):
            print(nums[i], end=' ')
        print('\n', end='')
        return

    for i in range(1, num_range + 1):
        nums[permutation_index] = i
        print_permutation(permutation_index + 1, num_max, length)


num_range, num_count = map(int, sys.stdin.readline().split())

print_permutation(0, num_range, num_count)
