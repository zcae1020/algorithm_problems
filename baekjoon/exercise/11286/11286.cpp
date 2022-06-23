#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    int n, x;
    priority_queue<pii> pq;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x)
            pq.push({-1 * abs(x), -x});
        else
        {
            if (pq.empty())
            {
                cout << "0\n";
                continue;
            }
            cout << -pq.top().second << '\n';
            pq.pop();
        }
    }
}

int main()
{
    FASTIO
    Solution();
}