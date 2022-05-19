#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int t, alpa[26];
string s;

void Input()
{
    cin >> s;
}

void Solution()
{
    memset(alpa, 0, sizeof(alpa));

    for (int i = 0; i < s.size(); i++)
    {
        if (++(alpa[s[i] - 'A']) % 3 == 0)
        {
            if (s[i] != s[i + 1])
            {
                cout << "FAKE" << '\n';
                return;
            }
            i++;
        }
    }
    cout << "OK" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        Input();
        Solution();
    }
}