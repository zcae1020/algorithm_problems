#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

string s;
int one, two, thr;

pii getAns(int num)
{
    bool ans = false;
    int idx = 0, st = num, end = num;
    while (1)
    {
        if (idx == s.length())
        {
            ans = true;
            break;
        }
        string ss = to_string(end);
        if (s.substr(idx, ss.length()) != ss)
            break;
        end++;
        idx += ss.length();
    }
    return ans ? pii(st, end - 1) : pii(-1, -1);
}

void Solution()
{
    cin >> s;
    one = stoi(s.substr(0, 1));
    two = stoi(s.substr(0, 2));
    thr = stoi(s.substr(0, 3));

    pii o = getAns(one), tw = getAns(two), th = getAns(thr);
    if (o != pii(-1, -1))
        cout << o.first << ' ' << o.second;
    else if (tw != pii(-1, -1))
        cout << tw.first << ' ' << tw.second;
    else
        cout << th.first << ' ' << th.second;
}

int main()
{
    FASTIO
    Solution();
}