import sys
import primecheck as pc

start, end = map(int, sys.stdin.readline().split())

for i in range(start, end + 1):
    if pc.is_prime(i) is True:
        print(i)
