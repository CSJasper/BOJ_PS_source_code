import sys


# 연산 결과의 최대 또는 최소를 찾는 함수
# 한 연산에 대해 결과 저장 -> 그 결과를 가지고 함수 다시 호출

tmp_add = []
tmp_sub = []
tmp_mul = []
tmp_div = []


def set_tmp(mode):

    if len(tmp_add) >= 1 or len(tmp_sub) >= 1 or len(tmp_mul) >= 1 or len(tmp_div) >= 1:
        tmp_add.clear()
        tmp_sub.clear()
        tmp_mul.clear()
        tmp_div.clear()

    if mode == 'max':
        tmp_add.append(MIN_RESULT)
        tmp_sub.append(MIN_RESULT)
        tmp_mul.append(MIN_RESULT)
        tmp_div.append(MIN_RESULT)
    elif mode == 'min':
        tmp_add.append(MAX_RESULT)
        tmp_sub.append(MAX_RESULT)
        tmp_mul.append(MAX_RESULT)
        tmp_div.append(MAX_RESULT)

# current value의 초기값은 numbers[0]이 된다.
def find_max(current_value, operation_count, numbers, index):
    if index >= len(numbers):
        return

    isLast = True
    add_candidate, sub_candidate, mul_candidate, div_candidate = MIN_RESULT, MIN_RESULT, MIN_RESULT, MIN_RESULT

    if operation_count['add'] != 0:
        operation_count['add'] -= 1
        tmp_add[0] = current_value[0] + numbers[index + 1]
        find_max(tmp_add, operation_count, numbers, index + 1)
        add_candidate = max((add_candidate, tmp_add[0]))
        operation_count['add'] += 1
        isLast = False

    if operation_count['sub'] != 0:
        operation_count['sub'] -= 1
        tmp_sub[0] = current_value[0] + numbers[index + 1]
        find_max(tmp_sub, operation_count, numbers, index + 1)
        sub_candidate = max((sub_candidate, tmp_sub[0]))
        operation_count['sub'] += 1
        isLast = False

    if operation_count['mul'] != 0:
        operation_count['mul'] -= 1
        tmp_mul[0] = current_value[0] * numbers[index + 1]
        find_max(tmp_mul, operation_count, numbers, index + 1)
        mul_candidate = max((mul_candidate, tmp_mul[0]))
        operation_count['mul'] += 1
        isLast = False

    if operation_count['div'] != 0:
        operation_count['div'] -= 1
        if current_value[0] < 0:
            pos = -current_value[0]
            tmp_div[0] = pos // numbers[index + 1]
            tmp_div[0] *= -1
        else:
            tmp_div[0] = current_value[0] // numbers[index + 1]

        find_max(tmp_div, operation_count, numbers, index + 1)
        div_candidate = max((div_candidate, tmp_div[0]))
        operation_count['div'] += 1
        isLast = False

    if not isLast:
        current_value[0] = max((add_candidate, sub_candidate, mul_candidate, div_candidate))
    else:
        return


def find_min(current_value, operation_count, numbers, index):
    if index >= len(numbers):
        return

    isLast = True
    add_candidate, sub_candidate, mul_candidate, div_candidate = MAX_RESULT, MAX_RESULT, MAX_RESULT, MAX_RESULT

    if operation_count['add'] != 0:
        operation_count['add'] -= 1
        tmp_add[0] = current_value[0] + numbers[index + 1]
        find_min(tmp_add, operation_count, numbers, index + 1)
        add_candidate = min((add_candidate, tmp_add[0]))
        operation_count['add'] += 1
        isLast = False

    if operation_count['sub'] != 0:
        operation_count['sub'] -= 1
        tmp_sub[0] = current_value[0] - numbers[index + 1]
        find_min(tmp_sub, operation_count, numbers, index + 1)
        sub_candidate = min((sub_candidate, tmp_sub[0]))
        operation_count['sub'] += 1
        isLast = False

    if operation_count['mul'] != 0:
        operation_count['mul'] -= 1
        tmp_mul[0] = current_value[0] * numbers[index + 1]
        find_min(tmp_mul, operation_count, numbers, index + 1)
        mul_candidate = min((mul_candidate, tmp_mul[0]))
        operation_count['mul'] += 1
        isLast = False

    if operation_count['div'] != 0:
        operation_count['div'] -= 1
        if current_value[0] < 0:
            pos = -current_value[0]
            tmp_div[0] = pos // numbers[index + 1]
            tmp_div[0] *= -1
        else:
            tmp_div[0] = current_value[0] // numbers[index + 1]
        find_min(tmp_div, operation_count, numbers, index + 1)
        div_candidate = min((div_candidate, tmp_div[0]))
        operation_count['div'] += 1
        isLast = False

    if not isLast:
        current_value[0] = min((add_candidate, sub_candidate, mul_candidate, div_candidate))
    else:
        return

MIN_RESULT = -int(10e10)
MAX_RESULT = int(10e10)
num_count = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
operation = {}
operation['add'], operation['sub'], operation['mul'], operation['div'] = map(int, sys.stdin.readline().split())

max_val = []
min_val = []

max_val.append(nums[0])
min_val.append(nums[0])

find_max(max_val, operation, nums, 0)
find_min(min_val, operation, nums, 0)

print(max_val[0])
print(min_val[0])

