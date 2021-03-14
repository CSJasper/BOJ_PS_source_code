import sys


def is_prime(number):
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


lBound = int(sys.stdin.readline())
uBound = int(sys.stdin.readline())
primeCount = 0
primeSum = 0
prime = []

for num in range(lBound, uBound + 1):
    if is_prime(num) is True:
        primeCount += 1
        primeSum += num
        prime.append(num)
    else:
        continue

if primeCount == 0:
    print(-1)
else:
    print(primeSum)
    print(min(prime))
