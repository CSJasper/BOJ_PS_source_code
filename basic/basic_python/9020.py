import sys

nums = []

test_num = int(sys.stdin.readline())
for i in range(test_num):
    tmp = int(sys.stdin.readline())
    nums.append(tmp)

max_input = max(nums)
prime_check = [True for n in range(max_input + 1)]
prime = []

prime_check[0] = False
prime_check[1] = False

for i in range(2, max_input + 1):
    if prime_check[i] is True:
        prime.append(i)  # prime 에는 소수가 크기순서대로 저장된다
        for j in range(i * i, max_input + 1, i):
            prime_check[j] = False

min_partition = ()
for currentNum in nums:
    min_dist = 10000  # 골드바흐 파티션의 길이가 10,000이 될 수 없다.
    for partition1 in prime:
        partition2 = currentNum - partition1
        if partition2 < partition1:  # 이 경우라면 중복이 발생한다
            break  # 중복이 발생한 이후부터는 더 이상 확인할 필요가 없다.
        if prime_check[partition2] is False:  # 골드바흐 파티션이 아니라면 넘어간다.
            continue
        dist = partition2 - partition1
        if min_dist > dist:
            min_dist = dist
            min_partition = (partition1, partition2)
    print(min_partition[0], min_partition[1])
