# quick sort를 이용하여 구해보자.
import sys


def partition(unsorted, left, right):
    low = left
    high = right + 1
    pivot = unsorted[left]
    while low < high:
        while low <= right and unsorted[low] < pivot:
            low += 1
        while high >= left and unsorted[high] > pivot:
            high -= 1
        if low < high:
            unsorted[low], unsorted[high] = unsorted[high], unsorted[low]

    return high


def quick_sort(unsorted, left, right):
    if left < right:
        q = partition(unsorted, left, right)
    quick_sort(unsorted, left, q-1)
    quick_sort(unsorted,q+1, right)


count = int(sys.stdin.readline())

arr = [0 for i in range(count)]

for i in range(count):
    arr[i] = int(sys.stdin.readline())


