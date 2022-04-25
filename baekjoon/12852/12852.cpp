#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, p[1000001];

void Input()
{
    cin >> n;
}

void Solution()
{
    queue<int> q, cnt;
    q.push(n), cnt.push(0);

    while (!q.empty())
    {
        int cur = q.front(), ccnt = cnt.front();
        q.pop(), cnt.pop();

        if (cur == 1)
        {
            cout << ccnt << '\n';
            break;
        }

        if (cur % 3 == 0 && p[cur / 3] == 0)
        {
            q.push(cur / 3);
            cnt.push(ccnt + 1);
            p[cur / 3] = cur;
        }
        if (cur % 2 == 0 && p[cur / 2] == 0)
        {
            q.push(cur / 2);
            cnt.push(ccnt + 1);
            p[cur / 2] = cur;
        }
        if (p[cur - 1] == 0)
        {
            q.push(cur - 1);
            cnt.push(ccnt + 1);
            p[cur - 1] = cur;
        }
    }

    vector<int> ans;
    int idx = 1;
    ans.push_back(idx);
    while (p[idx])
    {
        idx = p[idx];
        ans.push_back(idx);
    }

    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}