#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, X[200000], ans = 0;

void Input()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> X[i];
}

bool can(int m)
{
    int cur = 0, share = 1;
    for (int i = 1; i < N; i++)
    {
        if (X[i] - X[cur] >= m)
        {
            cur = i;
            share++;
        }
    }
    return share >= C;
}

void Solution()
{
    sort(X, X + N);
    int l = 1, r = 1e9 + 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (can(m))
        {
            ans = max(ans, m);
            l = m + 1;
        }
        else
            r = m - 1;
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