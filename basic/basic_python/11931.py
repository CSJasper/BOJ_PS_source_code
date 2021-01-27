# quick sort 를 이용하여 구해보자.
import sys


# unsorted 배열을 left 부터 right 까지 pivot 을 중심으로 pivot 보다 작은수는 왼쪽 pivot 보다 큰 수는 오른쪽에 위치하게끔 한다.
def partition(unsorted, left, right):
    # low, high 를 변수로 설정한 이유는 이놈들을 변화시키면서 볼 것이라서, 입력 매개변수를 훼손하지 않기 위해!
    low = left + 1
    high = right
    pivot = unsorted[left]
    # low 는 left + 1 에서 시작
    # low 와 high 의 순서가 엇갈리지 않을 때 까지 돌린다!
    while low <= high:
        # low 와 high 를 움직이되 unsorted[low] < pivot, unsorted[high] > pivot 이 될때까지 움직인다.(indicator)
        while low <= right and unsorted[low] < pivot:
            low += 1
        while high >= left and unsorted[high] > pivot:
            high -= 1
        # 여기까지 왔다는 의미는 위의 while 문에서 빠져나왔다는 소리이고, 그 이유는 엇갈렸거나, 아니면 pivot 의 대소관계에 변화가 생겨서이다.
        if low <= high:
            unsorted[low], unsorted[high] = unsorted[high], unsorted[low]

    return high  # pivot 의 위치 반환


def quick_sort(unsorted, left, right):
    if left < right:
        q = partition(unsorted, left, right)
        quick_sort(unsorted, left, q - 1)
        quick_sort(unsorted, q + 1, right)


count = int(sys.stdin.readline())

arr = [0 for i in range(count)]

for i in range(count):
    arr[i] = int(sys.stdin.readline())

quick_sort(arr, 0, count - 1)

for i in range(count - 1, -1, -1):
    print(arr[i])