#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string cowphabet, target;
int ans;

void Solution()
{
    cin >> cowphabet >> target;
    for (int i = 0; i < target.size();)
    {
        ans++;
        for (auto c : cowphabet)
        {
            if (i >= target.size())
            {
                break;
            }
            if (target[i] == c)
            {
                i++;
            }
        }
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}