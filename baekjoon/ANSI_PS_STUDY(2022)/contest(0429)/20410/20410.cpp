#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int m, seed, x1, x2;
vector<pii> ac;

void Input()
{
    cin >> m >> seed >> x1 >> x2;
}

void Solution()
{
    for (int a = 0; a < m; a++)
        for (int c = 0; c < m; c++)
            if ((a * seed + c) % m == x1)
                ac.push_back({a, c});

    for (auto p : ac)
    {
        if ((p.first * x1 + p.second) % m == x2)
        {
            cout << p.first << ' ' << p.second;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}