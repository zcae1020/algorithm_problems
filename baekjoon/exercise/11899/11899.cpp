#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int cnt, ans;
string str;

void Solution()
{
    cin >> str;
    for (auto c : str)
    {
        if (c == '(')
            cnt++;
        else
        {
            if (!cnt)
                ans++;
            else
                cnt--;
        }
    }

    cout << ans + cnt;
}

int main()
{
    FASTIO
    Solution();
}