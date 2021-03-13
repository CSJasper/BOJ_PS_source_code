import sys


def is_prime(number):  # 소수 판정은 sqrt(N) 이하의 숫자로 나누어지지 않는다면 소수이다를 이용한다.
    if number == 1:
        return False
    i = 2
    while i * i <= number:
        if number % i == 0:
            return False
        else:
            pass
        i += 1
    return True


totalNum = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
primeCount = 0

for idx in range(totalNum):
    if is_prime(nums[idx]) is True:
        primeCount += 1
    else:
        continue

print(primeCount)
