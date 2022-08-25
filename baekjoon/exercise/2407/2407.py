n, r = input().split()

n = int(n)
r = int(r)

ans = 1

for i in range(n-r+1, n+1):
    ans*=i

for i in range(2,r+1):
    ans//=i

print(ans)