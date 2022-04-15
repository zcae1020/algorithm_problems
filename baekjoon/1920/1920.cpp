#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> nv, mv;

void Input()
{
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nv.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        mv.push_back(a);
    }
    sort(nv.begin(), nv.end());
}

bool bs(int target)
{
    int l = 0, r = n - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (nv[m] == target)
            return 1;
        else if (nv[m] > target)
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}

void Solution()
{
    for (int i = 0; i < m; i++)
    {
        if (bs(mv[i]))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}