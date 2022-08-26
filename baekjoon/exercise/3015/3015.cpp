#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

stack<pii> s;
int n;
ll ans;

void push(int x)
{
    int cnt = 1;
    while (s.size())
    {
        if (s.top().first < x)
        {
            ans += s.top().second;
            s.pop();
        }
        else if (s.top().first == x)
        {
            ans += s.top().second;
            cnt += s.top().second;
            s.pop();
        }
        else //s.top().first > x
        {
            ans++;
            break;
        }
    }
    s.push({x, cnt});
}

void Solution()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(x);
    }
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}