#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, ans, num[26];;
string sarr[10];

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sarr[i];
        for (int j = sarr[i].size() - 1, k = 1; j >= 0; j--, k *= 10)
            num[sarr[i][j] - 'A'] += k;
    }

    sort(num, num + 26, greater<int>());
    for (int i = 0, j = 9; i < 10; i++, j--)
        ans += num[i] * j;
    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}