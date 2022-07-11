#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    int a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];

    sort(a, a + 3);

    if (a[0] == a[1])
    {
        if (a[1] == a[2])
            cout << 10000 + a[1] * 1000;
        else
            cout << 1000 + a[1] * 100;
    }
    else if (a[1] == a[2])
        cout << 1000 + a[1] * 100;
    else
        cout << a[2] * 100;
}

int main()
{
    FASTIO
    Solution();
}