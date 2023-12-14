import sys, heapq

n = int(sys.stdin.readline())
arr = []
height = [0] * n
q = []

end = [0] * n
check = set()
for i in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    arr.append((a, i, 1))
    arr.append((c, i, -1))
    height[i] = b
    end[i] = c

arr.sort(key=lambda x : (x[0], -x[2], -height[x[1]]))

now = 0
ans = []
for i in range(len(arr)):
    point, idx, dir = arr[i]
    if dir == 1:
        if now < height[idx]:
            now = height[idx]
            ans.append((point, now))
        heapq.heappush(q, (-height[idx], end[idx]))

    else:
        check.add(point)
        while q:
            if q[0][1] not in check:
                break
            heapq.heappop(q)
            
        if not q:
            if now:
                now = 0
                ans.append((point, now))
                
        else:
            if -q[0][0] != now:
                now = -q[0][0]
                ans.append((point, now))

for i in ans:
    print(i[0], i[1], end=' ')