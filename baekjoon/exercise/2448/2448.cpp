#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

const int maxn = 1024 * 3;

int n;
bool m[maxn][2 * maxn];
bool three[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1}};

void dq(int x, int y, int c)
{
    if (c == 3)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                m[x + i][y + j] = three[i][j];
        return;
    }

    dq(x, y + c / 2, c / 2);
    dq(x + c / 2, y, c / 2);
    dq(x + c / 2, y + c, c / 2);
}

void Solution()
{
    cin >> n;
    dq(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cout << (m[i][j] ? '*' : ' ');
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}