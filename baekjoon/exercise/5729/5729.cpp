#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

void Solution()
{
    while (1)
    {
        int n, a[10000], sum = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum+=a[i];
        }

        bool isAns = 1;
        int ans = 0;
        for(int i=n;i>2;i--){
            if(sum%i==0){
                int dist = sum/i;
                ans = 0;

                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        
                    }
                }             

                if (cur >= dist)
                {
                    int p = 0;
                    while (p < dist)
                    {
                        ans++;
                        p += s.top();
                        s.pop();
                    }
                    cur -= p;
                    ans--;
                    if (p > dist)
                    {
                        isAns = 0;
                        break;
                    }
                }

                if(isAns)
                    break;
            }
        }
        cout<<(isAns&&n-ans>2?ans:-1)<<'\n';
    }
}

int main()
{
    FASTIO
    Solution();
}