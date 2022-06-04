#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int arr[20], ans, ns;

int getSum()
{
    int sum = 1;
    bool overTen = false;
    for (int i = 0; i < ns; i++)
    {
        if (arr[i] >= 10)
        {
            overTen = true;
            sum *= (19 - arr[i]);
        }
        else
            sum *= (arr[i] + 1);
    }
    if (!overTen)
        sum -= 2;
    return sum;
}

void dfs(int idx)
{
    ans += getSum();
    for (int i = idx; i < ns; i++)
    {
        if (i + 2 >= ns)
            return;
        if (arr[i])
        {
            arr[i]--;
            arr[i + 2] += 10;
            dfs(i + 1);
            arr[i]++;
            arr[i + 2] -= 10;
        }
    }
}

void Solution()
{
    string n;
    cin >> n;
    ans = 0;
    ns = n.size();
    for (int i = 0; i < ns; i++)
        arr[i] = n[i] - '0';

    dfs(0);
    cout << ans << '\n';
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}