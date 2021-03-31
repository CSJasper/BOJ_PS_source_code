import sys

SUDOKU_SIZE = 9

sudoku = [[0 for i in range(SUDOKU_SIZE)] for j in range(SUDOKU_SIZE)]


def solve(count):
    x = count // SUDOKU_SIZE
    y = count % SUDOKU_SIZE
    square_idx = (x // 3) * 3 + (y // 3)

    if count >= SUDOKU_SIZE * SUDOKU_SIZE:
        for i in range(SUDOKU_SIZE):
            for j in range(SUDOKU_SIZE):
                print(sudoku[i][j], end=' ')
            print('\n', end='')
        sys.exit(0)

    if sudoku[x][y] == 0:
        for num in range(1, 10):
            if isRowExist[x][num] is False and isColumnExist[y][num] is False and isSquareExist[square_idx][num] is False:
                isRowExist[x][num] = True
                isColumnExist[y][num] = True
                isSquareExist[square_idx][num] = True
                sudoku[x][y] = num
                solve(count + 1)
                sudoku[x][y] = 0
                isSquareExist[square_idx][num] = False
                isColumnExist[y][num] = False
                isRowExist[x][num] = False
    else:
        solve(count + 1)


isRowExist = [[False for i in range(10)] for j in range(SUDOKU_SIZE)]
isColumnExist = [[False for i in range(10)] for j in range(SUDOKU_SIZE)]
isSquareExist = [[False for i in range(10)] for j in range(SUDOKU_SIZE)]

for i in range(SUDOKU_SIZE):
    sudoku[i] = list(map(int, sys.stdin.readline().split()))

for i in range(SUDOKU_SIZE):
    for j in range(SUDOKU_SIZE):
        if sudoku[i][j] != 0:
            isRowExist[i][sudoku[i][j]] = True
            isColumnExist[j][sudoku[i][j]] = True
            isSquareExist[(i // 3) * 3 + (j // 3)][sudoku[i][j]] = True

solve(0)
