#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

ll n, arr[5000], mn = 1e10, ans[3];

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            ll sum = arr[i] + arr[l] + arr[r];
            if (mn > abs(sum))
            {
                mn = abs(sum);
                ans[0] = arr[i];
                ans[1] = arr[l];
                ans[2] = arr[r];
            }
            if (sum < 0)
                l++;
            else
                r--;
        }
    }

    for (int i = 0; i < 3; i++)
        cout << ans[i] << ' ';
}

int main()
{
    FASTIO
    Solution();
}