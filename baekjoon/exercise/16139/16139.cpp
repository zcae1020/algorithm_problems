#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 2e5 + 10;

string s;
int q, psum[maxn][26];

void Solution()
{
    cin >> s >> q;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
            psum[i + 1][j] = psum[i][j];
        psum[i + 1][s[i] - 'a']++;
    }

    while (q--)
    {
        char a;
        int b, c;
        cin >> a >> b >> c;

        cout << psum[c + 1][a - 'a'] - psum[b][a - 'a'] << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}