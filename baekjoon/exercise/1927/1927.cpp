#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    int n, x;
    priority_queue<int> pq;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(-x);
    }
}

int main()
{
    FASTIO
    Solution();
}