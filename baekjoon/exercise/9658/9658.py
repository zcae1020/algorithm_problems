n = int(input())

dx = [1,3,4]

dp = [0]*(1001)

dp[2] = dp[4] = dp[5] = 1

for i in range(6, 1001):
    for j in dx:
        if not dp[i-j]:
            dp[i] = 1
            break

if dp[n]:
    print("SK")
else:
    print("CY")