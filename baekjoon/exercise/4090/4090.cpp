#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

vector<int> vamnum, permu;
int n, ten[10];

bool dfs(bool start, int idx)
{
    bool ret = false;
    if (!idx)
    {
        int num = 0;
        for (int i = 1, j = permu.size() - 1; j >= 0; i *= 10, j--)
            num += permu[j] * i;

        if (n % num == 0)
        {
            int d = n / num;
            int tten[10] = {0};
            while (d)
            {
                tten[d % 10]++;
                d /= 10;
            }

            for (int i = 0; i < 10; i++)
                if (ten[i] != tten[i])
                    return false;
            return true;
        }
        return false;
    }
    for (int i = start ? 1 : 0; i < 10; i++)
    {
        if (ten[i])
        {
            ten[i]--;
            permu.push_back(i);
            ret = ret || dfs(0, idx - 1);
            permu.pop_back();
            ten[i]++;
        }
        if (ret)
            return ret;
    }

    return ret;
}

bool isVampire(int x)
{
    string s = to_string(x);
    memset(ten, 0, sizeof(ten));

    for (auto c : s)
        ten[c - '0']++;

    for (int i = 1; i <= s.size() / 2; i++)
    {
        permu.clear();
        if (dfs(1, i))
            return true;
    }
    return false;
}

void Solution()
{
    vamnum.push_back(126);
    vamnum.push_back(153);

    for (n = 154; n < 1e6 + 1000; n++)
        if (isVampire(n))
            vamnum.push_back(n);

    while (true)
    {
        int x;
        cin >> x;
        if (!x)
            return;
        for (int i = 0; i < vamnum.size(); i++)
        {
            if (vamnum[i] >= x)
            {
                cout << vamnum[i] << '\n';
                break;
            }
        }
    }
}

int main()
{
    FASTIO
    Solution();
}