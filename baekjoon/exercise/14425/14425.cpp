#include <iostream>
#include <string>
#include <set>

using namespace std;

int N, M, ans;
set<string> s;

void Input()
{
    cin >> N >> M;
    while (N--)
    {
        string t;
        cin >> t;
        s.insert(t);
    }
}

void Solution()
{
    while (M--)
    {
        string t;
        cin >> t;
        if (s.count(t))
            ans++;
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