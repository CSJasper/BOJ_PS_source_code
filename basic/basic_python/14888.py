import sys

# 더하거나 곱할수록 숫자는 커진다, 빼거나 나눌수록 숫자는 작아진다
# 어떤 연산을 해서 나온
nums_num = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
nums.sort()
operation_num = list(map(int, sys.stdin.readline().split()))  # 0 : 더하기, 1 : 빼기, 2 : 곱하기, 3 : 나누기


