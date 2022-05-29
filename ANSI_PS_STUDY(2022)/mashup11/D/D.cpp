#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

void Solution()
{
    ll sum = 0;
    int n;
    queue<ll> pq;
    map<ll, int> m;

    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
        m[tmp]++;
    }

    if (n == 1)
    {
        cout << "YES\n";
        return;
    }

    pq.push(sum);
    while (pq.size() < n)
    {
        ll cur = pq.front();
        pq.pop();

        ll p1 = cur / 2, p2 = (cur + 1) / 2;
        if (m[p1])
            m[p1]--, n--;
        else
            pq.push(p1);
        if (m[p2])
            m[p2]--, n--;
        else
            pq.push(p2);
    }
    if (pq.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    while (tc--)
        Solution();
}