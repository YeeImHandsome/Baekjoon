import sys
S = sys.stdin.readline().strip()
x = sys.stdin.readline().strip()
i = 0
cnt = 0
while i < len(S):
    if S[i:i+len(x)] == x:
        i += len(x)
        cnt += 1
    else :
        i += 1
print(cnt)