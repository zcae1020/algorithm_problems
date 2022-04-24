#include <iostream>

using namespace std;

int n, m, tree[1000000], ans;

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> tree[i];
}

long long getSum(int h)
{
    long long ret = 0;
    for (int i = 0; i < n; i++)
        ret += (tree[i] - h > 0 ? tree[i] - h : 0);
    return ret;
}

void Solution()
{
    int l = 0, r = 1000000000, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (getSum(mid) >= m)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
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