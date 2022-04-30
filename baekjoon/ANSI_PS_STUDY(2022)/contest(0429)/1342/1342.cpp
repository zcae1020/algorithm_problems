#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int alpa[26], ans;
vector<int> str;

void Input()
{
    cin >> s;
}

void DFS()
{
    if (str.size() == s.size())
    {
        ans++;
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (alpa[i])
        {
            if (!str.empty() && str.back() == i)
                continue;
            alpa[i]--;
            str.push_back(i);
            DFS();
            str.pop_back();
            alpa[i]++;
        }
    }
}

void Solution()
{
    for (auto c : s)
        alpa[c - 'a']++;
    DFS();
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}