N = int(input())
i = 666

while True: 
    if '666' in str(i):
        N = N - 1
        if N == 0:
            break
    i = i + 1
    
print(i)