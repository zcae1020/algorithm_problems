#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;
long long ans;
vector<int> mn, pu;

void Input()
{
    cin >> N;
    int a;
    while (N--)
    {
        cin >> a;
        if (a < 1)
            mn.push_back(a);
        else if (a > 1)
            pu.push_back(a);
        else
            ans++;
    }
}

void Solution()
{

    sort(mn.begin(), mn.end());
    sort(pu.begin(), pu.end(), greater<>());

    for (int i = 0; i < mn.size(); i++)
    {
        if (i + 1 < mn.size())
        {
            ans += mn[i] * mn[i + 1];
            i++;
        }
        else
            ans += mn[i];
    }

    for (int i = 0; i < pu.size(); i++)
    {
        if (i + 1 < pu.size())
        {
            ans += pu[i] * pu[i + 1];
            i++;
        }
        else
            ans += pu[i];
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}