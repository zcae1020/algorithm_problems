#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void Solution()
{
    int arr[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    set<int> s;
    queue<int> qx, qy, cnt, val;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            qx.push(i), qy.push(j), cnt.push(1), val.push(arr[i][j]);

            while (qx.size())
            {
                int cx = qx.front(), cy = qy.front(), cc = cnt.front(), cv = val.front();
                qx.pop(), qy.pop(), cnt.pop(), val.pop();

                if (cc == 6)
                {
                    s.insert(cv);
                    continue;
                }

                cv *= 10;
                for (int i = 0; i < 4; i++)
                {
                    int nx = cx + dx[i], ny = cy + dy[i];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                        continue;
                    qx.push(nx), qy.push(ny), cnt.push(cc + 1), val.push(cv + arr[nx][ny]);
                }
            }
        }
    }
    cout << s.size();
}

int main()
{
    FASTIO
    Solution();
}