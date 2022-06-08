#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXT = 32;

int n, q, arr[MAXN], mn;
ll power2[MAXT], sum;
vector<int> cnt(MAXT);

int getPower2(int idx, int need, vector<int> &v)
{
    if (idx < 0)
        return 0;
    if (v[idx] >= need)
    {
        v[idx] -= need;
        return need;
    }
    else
    {
        int ret = v[idx], gp = getPower2(idx - 1, (need - v[idx]) * 2, v);
        v[idx] = 0;
        return (gp ? ret + gp : gp);
    }
}

void Solution()
{

    power2[0] = 1;
    for (int i = 1; i < MAXT; i++)
        power2[i] = power2[i - 1] * 2;

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < MAXT; j++)
        {
            if (arr[i] == power2[j])
            {
                cnt[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < MAXT; i++)
    {
        if (cnt[i])
        {
            mn = power2[i];
            break;
        }
    }

    while (q--)
    {
        int qu, idx, ret, ans = 0;
        bool getAns = false;
        vector<int> tcnt(cnt);
        cin >> qu;
        while (qu)
        {

            for (int i = 0; i < MAXT; i++)
            {

                if (qu == power2[i])
                {
                    ret = getPower2(i, 1, tcnt);
                    if (!ret)
                        ans = -1;
                    else
                        ans += ret;
                    getAns = true;
                    break;
                }

                if (qu < power2[i])
                {
                    ret = getPower2(i - 1, 1, tcnt);
                    if (!ret)
                    {
                        ans = -1;
                        getAns = true;
                    }
                    else
                    {
                        ans += ret;
                        qu -= power2[i - 1];
                    }
                    break;
                }
            }

            if (getAns)
                break;
        }

        cout << ans << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}