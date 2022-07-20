#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 3e5 + 10;

int n, arr[maxn];
string s;
vector<int> v;

void Solution()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[0] != s[i])
        {
            start = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[n - 1] != s[i])
        {
            end = i + 1;
            break;
        }
    }

    if (start == -1 || start == end)
    {
        cout << 0;
        return;
    }

    int mx = arr[start];
    for (int i = start + 1; i < end; i++)
    {
        if (s[i - 1] != s[i])
        {
            v.push_back(mx);
            mx = 0;
        }
        mx = max(mx, arr[i]);
    }
    v.push_back(mx);

    ll ans = 0;
    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < (v.size() + 1) / 2; i++)
        ans += v[i];

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}