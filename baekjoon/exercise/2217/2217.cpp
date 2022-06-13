#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 1e5 + 10;

int n, arr[maxn], ans;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i]*(i+1));
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}