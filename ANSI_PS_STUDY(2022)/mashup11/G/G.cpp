#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int MAX = 2e3 + 10;
char m[MAX][MAX];

void Solution()
{
    int n, one = 0, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == '1')
                one++;
        }
    }

    for (int s = 0; s < n; s++)
    {
        int cnt = 0;
        for (int i = 0, j = s; i < n; i++, j = (j + 1) % n)
            if (m[i][j] == '1')
                cnt++;
        mx = max(mx, cnt);
    }
    cout << one - mx + n - mx << '\n';
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}