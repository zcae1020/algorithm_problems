#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int t, n, m, a[1005], b[1005], apsum[1005], bpsum[1005];
ll ans;
map<int, int> ma;

void Solution()
{
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        apsum[i] = apsum[i - 1] + a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        bpsum[i] = bpsum[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            ma[apsum[i] - apsum[j]]++;

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < i; j++)
            ans += ma[t - (bpsum[i] - bpsum[j])];

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}