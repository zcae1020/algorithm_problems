#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> v, ans;

void Input()
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        char a;
        cin >> a;
        v.push_back(a);
    }
}

bool isAeiou(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return true;
    return false;
}

void DFS(int idx, int len, int aeiou, int etc)
{
    if (idx > c)
        return;
    if (len == l)
    {
        if (aeiou >= 1 && etc >= 2)
        {
            for (auto a : ans)
                cout << a;
            cout << '\n';
        }
        return;
    }
    ans.push_back(v[idx]);
    if (isAeiou(v[idx]))
        DFS(idx + 1, len + 1, aeiou + 1, etc);
    else
        DFS(idx + 1, len + 1, aeiou, etc + 1);
    ans.pop_back();
    DFS(idx + 1, len, aeiou, etc);
}

void Solution()
{
    sort(v.begin(), v.end());
    DFS(0, 0, 0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}