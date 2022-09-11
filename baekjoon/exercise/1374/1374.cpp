#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e5;

int N, ans;
pii arr[maxn];
priority_queue<int> pq;

void Solution()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x >> arr[i].fs >> arr[i].sd;
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        while (!pq.empty())
        {
            if (-pq.top() > arr[i].fs)
                break;
            pq.pop();
        }

        pq.push(-arr[i].sd);
        ans = max((int)pq.size(), ans);
    }

    cout << ans;
}

int main()
{
    FASTIO
    Solution();
}