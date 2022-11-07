#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
string arr[64];

bool isEqual(int sx, int ex, int sy, int ey)
{
    for (int i = sx; i < ex; i++)
    {
        for (int j = sy; j < ey; j++)
        {
            if (arr[sx][sy] != arr[i][j])
                return false;
        }
    }

    return true;
}

string getAns(int sx, int ex, int sy, int ey)
{
    string ret;

    if (isEqual(sx, ex, sy, ey))
    {
        return arr[sx][sy] == '1' ? "1" : "0";
    }

    ret = "(" +
          getAns(sx, (sx + ex) / 2, sy, (sy + ey) / 2) +
          getAns(sx, (sx + ex) / 2, (sy + ey) / 2, ey) +
          getAns((sx + ex) / 2, ex, sy, (sy + ey) / 2) +
          getAns((sx + ex) / 2, ex, (sy + ey) / 2, ey) +
          ")";

    return ret;
}

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getAns(0, n, 0, n);
}

int main()
{
    FASTIO
    Solution();
}