#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> a, b;
multiset<int> ms;

void Input()
{
    cin >> n;

    a.clear();
    b.clear();
    ms.clear();

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
}

void Solution()
{
    int aidx, bidx;
    aidx = bidx = n - 1;

    while (bidx >= 0)
    {
        if (a[aidx] == b[bidx])
        {
            int cur = b[bidx];
            bidx--, aidx--;
            while (bidx >= 0 && cur == b[bidx])
            {
                ms.insert(cur);
                bidx--;
            }
        }
        else
        {
            if (ms.count(a[aidx]))
            {
                ms.erase(ms.lower_bound(a[aidx]));
                aidx--;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;
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