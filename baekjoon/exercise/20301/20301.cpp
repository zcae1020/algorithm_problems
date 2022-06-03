#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int n, k, m;
deque<int> dq;

void Solution()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    int kcnt = 0, mcnt = 0;
    bool flag = false;
    while (dq.size())
    {

        if (mcnt == m)
        {
            mcnt = 0;
            flag = flag ? false : true;
        }

        kcnt++;

        if (kcnt == k)
        {
            if (flag)
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            kcnt = 0;
            mcnt++;
            continue;
        }

        if (flag)
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        else
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
}

int main()
{
    FASTIO
    Solution();
}