p1, p2, p3, input = map(int, input().split(' '))

arr = []
INF = 10**18

for i in range(0, 60):
    for j in range(0,60):
        for k in range(0,60):
            if p1**i * p2**j * p3**k<=INF:
                arr.append(p1**i * p2**j * p3**k)

arr.sort()

print(arr[input])