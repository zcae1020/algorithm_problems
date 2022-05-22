#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
bool ans;

void Input()
{
    cin >> s >> t;
}

void Solution()
{
    while (s.size() < t.size())
    {
        if (t.back() == 'B')
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        else
            t.pop_back();
    }
    if (s == t)
        cout << 1;
    else
        cout << 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}