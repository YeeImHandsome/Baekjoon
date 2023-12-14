import sys; input = sys.stdin.readline

dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

while True:
    R, C = map(int, input().split())
    if not R: break
    L = [input().strip() for _ in range(R)]

    result = [[0] * C for _ in range(R)]

    for i in range(R):
        for j in range(C):
            if L[i][j] == '*':
                for di, dj in dir:
                    if 0 <= i + di < R and 0 <= j + dj < C:
                        result[i + di][j + dj] += 1

    for i in range(R):
        for j in range(C):
            if L[i][j] == '*': 
                print('*', end = '')
            else:
                print(result[i][j], end = '')
        print()