#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, m;
vector<int> a, b;

void Solution()
{
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int j = 0; j < m; j++)
    {
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int aidx = 0, bidx = 0, cnt = 0;
    while (aidx < n && bidx < m)
    {
        if (a[aidx] == b[bidx])
        {
            cnt++;
            aidx++;
            bidx++;
        }
        else if (a[aidx] < b[bidx])
            aidx++;
        else if (a[aidx] > b[bidx])
            bidx++;
    }

    cout << a.size() + b.size() - 2 * cnt;
}

int main()
{
    FASTIO
    Solution();
}