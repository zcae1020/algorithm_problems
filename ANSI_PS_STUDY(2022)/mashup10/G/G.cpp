#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n;
vector<int> cnt;
vector<pii> a, b;

void Input()
{
    cin >> n;

    cnt.clear();
    a.clear();
    b.clear();
    cnt.resize(n + 100);

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (a.size() && a.back().first == tmp)
            a.back().second++;
        else
            a.push_back({tmp, 1});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (b.size() && b.back().first == tmp)
            b.back().second++;
        else
            b.push_back({tmp, 1});
    }
}

void Solution()
{
    for (int i = 0; i < b.size(); i++)
    {
        if (a.empty())
        {
            cout << "NO\n";
            return;
        }

        if (a[0].first == b[i].first)
        {
            a[0].second += cnt[a[0].first];
            cnt[a[0].first] = 0;
            if (a[0].second == b[i].second)
                a.erase(a.begin());
            else if (a[0].second > b[i].second)
                a[0].second -= b[i].second;
            else
            {
                b[i].second -= a[0].second;
                a.erase(a.begin());
                i--;
            }
        }
        else
        {
            cnt[a[0].first] += a[0].second;
            a.erase(a.begin());
            i--;
        }
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        Input();
        Solution();
    }
}