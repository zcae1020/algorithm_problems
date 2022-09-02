#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e6;

int n, x, cp[maxn];
pii arr[maxn];
priority_queue<pii> pq;
priority_queue<int> cnt;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr + n);
    cnt.push(0);

    for (int i = 0; i < n; i++)
    {
        while (pq.size() && -pq.top().fs < arr[i].fs)
        {
            cnt.push(pq.top().sd);
            pq.pop();
        }

        if (cnt.size() == 1)
        {
            x = -cnt.top() + 1;
            cnt.push(-x);
        }

        pq.push({-arr[i].sd, cnt.top()});
        cp[-cnt.top()]++;
        cnt.pop();
    }

    cout << x << '\n';
    for (int i = 0; i < x; i++)
        cout << cp[i] << ' ';
}

int main()
{
    FASTIO
    Solution();
}