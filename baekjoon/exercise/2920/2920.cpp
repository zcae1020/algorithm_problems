#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int a[8];

void Solution()
{
    for (int i = 0; i < 8; i++)
        cin >> a[i];

    bool flag = 0;
    for (int i = 1; i <= 8; i++)
    {
        if (a[i - 1] != i)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "ascending";
        return;
    }

    flag = 0;
    for (int i = 1; i <= 8; i++)
    {
        if (a[8 - i] != i)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "descending";
        return;
    }
    cout << "mixed";
}

int main()
{
    FASTIO
    Solution();
}