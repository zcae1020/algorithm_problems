#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int MAX = 2e5 + 10;

int n, arr[MAX], ans;
map<ll,int> m;
multiset<ll> ms;
ll sarr[MAX], t;

void Solution()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sarr[0] = arr[0];
    ms.insert(sarr[0]);
    for (int i = 1; i < n; i++)
    {
        sarr[i] = sarr[i - 1] + arr[i];
        ms.insert(sarr[i]);
    }

    ll p = -1e16;
    for(auto a: ms){
        if(p==-1e16)
            m[a]=ms.count(a);
        else
            m[a]=m[p]+ms.count(a);
        p = a;
    }

    for (auto a : ms)
    {
        if (a < t)
            ans += ms.count(a);
        else
            break;
    }

    for (int i = 0; i < n; i++)
    {
        ms.erase(ms.find(sarr[i]));
        for (auto a : ms)
        {
            if (a - sarr[i] < t)
                ans += ms.count(a);
            else
                break;
        }
    }
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}