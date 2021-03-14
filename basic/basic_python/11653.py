import sys


def is_prime(number):
    if number == 1:
        return False
    i_func = 2
    while i_func * i_func <= number:
        if number % i_func == 0:
            return False
        i_func += 1
    return True


num = int(sys.stdin.readline())

i = 2
while i * i <= num:
    if is_prime(i) is True:
        while num % i == 0:
            print(i)
            num //= i
        i += 1
    else:
        i += 1
        continue

if is_prime(num) is True:
    print(num)
else:
    i = 2
    while i * i <= num:
        if is_prime(i) is True:
            while num % i == 0:
                print(i)
                num //= i
            i += 1

        else:
            i += 1
            continue

# sqrt(n) 이하의 숫자로 나누어 떨어지지 않으면 n은 소수이다.
# n이 합성수이면 (sqrt(n) 이하의 숫자로 나누어 떨어지지 않는다)가 거짓이다.
# 만약 sqrt(i) 이하의 숫자로 전부 나누어 지지 않는다면 그 수는 소수 즉 자기 자신을 출력해야 한다.
# 만약 sqrt(i) 이하의 숫자로 나누어 진다면 그 수는 합성수이고 sqrt(i) 초과의 소인수가 있을 수도 있다.

