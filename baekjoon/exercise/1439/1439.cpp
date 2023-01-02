#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string str;
char cur;
int zero, one;

void Solution()
{
    cin >> str;

    cur = str[0];
    if (cur == '0')
    {
        zero++;
    }
    else
    {
        one++;
    }
    
    for (auto c : str)
    {
        if (c != cur)
        {
            cur = c;
            if (cur == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
    }

    cout << (zero > one ? one : zero);
}

int main()
{
    FASTIO
    Solution();
}