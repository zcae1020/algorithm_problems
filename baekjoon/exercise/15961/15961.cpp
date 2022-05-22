#include <iostream>

using namespace std;

int n, d, k, c, cur, ans, arr[3000000], have[3001];

void Input()
{
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        if (have[arr[i]]++ == 0)
            cur++;
    if (have[c]++ == 0)
        cur++;
    ans = cur;
}

void Solution()
{
    int l = 0, r = k;
    while (l < n)
    {
        if (--have[arr[l]] == 0)
            cur--;
        if (have[arr[r]]++ == 0)
            cur++;
        l++, r = (r + 1) % n;
        ans = max(ans, cur);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}