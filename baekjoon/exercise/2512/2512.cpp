#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, arr[10000], ans;

bool check(int num)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (num >= arr[i] ? arr[i] : num);

    return sum <= m;
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;

    sort(arr, arr + n);

    int l = 1, r = arr[n - 1];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}