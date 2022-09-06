#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll n, sum, i = 1;

void Solution()
{
    cin >> n;
    while (1)
    {
        sum += i++;
        if (sum + i > n)
        {
            cout << i - 1;
            return;
        }
    }
}

int main()
{
    FASTIO
    Solution();
}