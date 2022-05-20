#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxN = 2e5 + 7;

int T, n, son[maxN], cnt[maxN];

bool cmp(int x, int y)
{
    
    return x > y;
}

bool check(int x)
{
    
    int sum = 0;
    for(int i = 1; i <= cnt[0]; ++i) {
    
        if(cnt[i] > x)
            sum += cnt[i] - x;
        else
            break;
    }
    return sum <= x;
}

int main()
{
    
    scanf("%d", &T);
    while(T--) {
    
        memset(son, 0, sizeof son);
        cnt[0] = 0;
        scanf("%d", &n);
        for(int i = 1; i < n; ++i) {
    
            int x; scanf("%d", &x);
            son[x]++;
        }
        sort(son + 1, son + 1 + n, cmp);
        int mt = 0;
        while(son[n] == 0)
            n--;
        for(int i = 1; i <= n; ++i) {
    
            ++mt;
            son[i] -= (n - i + 1);
            if(son[i] > 1)
                cnt[++cnt[0]] = son[i] - 1;
        }
        if(cnt[0] == 0) 
            printf("%d\n", mt + 1);
        else {
    
            sort(cnt + 1, cnt + 1 + cnt[0], cmp);
            int sum = 0;
            for(int i = 1; i <= cnt[0]; ++i)
                sum += cnt[i];
            int l = 1, r = sum;
            while(l < r) {
    
                int mid = (l + r) >> 1;
                if(check(mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            printf("%d\n", l + mt + 1);
        }
    }
    return 0;   
}
