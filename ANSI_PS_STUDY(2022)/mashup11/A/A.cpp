#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;

void Input()
{
    cin >> n >> k >> s;
}

void Solution()
{
    int idx = -1, mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] - k > 'a')
        {
            idx = i;
            break;
        }
        else
            mx = max(mx, s[i] - 'a');
    }

    if (idx == -1)
    {
        for (int i = 0; i < n; i++)
            cout << 'a';
        cout << '\n';
        return;
    }

    k -= mx;
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= 'a' + mx)
            cout << 'a';
        else if ((s[idx] - k) <= s[i] && s[i] <= s[idx])
            cout << (char)(s[idx] - k);
        else
            cout << s[i];
    }
    cout << '\n';
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