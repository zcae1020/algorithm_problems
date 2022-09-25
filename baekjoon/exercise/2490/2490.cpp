#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

void Solution()
{
    for (int tc = 0; tc < 3; tc++)
    {
        int cnt = 0, a;
        for (int i = 0; i < 4; i++)
        {
            cin >> a;
            if (!a)
                cnt++;
        }

        cout << (char)(cnt ? 'A' + cnt - 1 : 'E') << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}