#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int maxn = 1e5+10;

int rcnt[maxn], ccnt[maxn];
pii rconti[maxn], cconti[maxn];

set<pii> sx, sy;

void Solution()
{
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int t, x1, x2, y1, y2;
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> x1 >> y1;

            if (rcnt[x1] == 0)
            {
                if (x1 + 1 <= n && x1 - 1 > 0 && rcnt[x1 + 1] && rcnt[x1 - 1])
                {
                    pii cur = {rconti[x1 - 1].first, rconti[x1 + 1].second};
                    for (int i = rconti[x1 - 1].first; i <= rconti[x1 + 1].second; i++)
                        rconti[i] = cur;
                }
                else if (x1 + 1 <= n && rcnt[x1 + 1])
                {
                    pii cur = {x1, rconti[x1 + 1].second};
                    for (int i = x1; i <= rconti[x1 + 1].second; i++)
                        rconti[i] = cur;
                }
                else if (x1 - 1 > 0 && rcnt[x1 - 1])
                {
                    pii cur = {rconti[x1 - 1].first, x1};
                    for (int i = rconti[x1 - 1].first; i <= x1; i++)
                        rconti[i] = cur;
                }
                else
                    sx.insert(x1,x1);
            }
            rcnt[x1]++;

            if (ccnt[y1] == 0)
            {
                if (y1 + 1 <= n && y1 - 1 > 0 && ccnt[y1 + 1] && ccnt[y1 - 1])
                {
                    pii cur = {cconti[y1 - 1].first, cconti[y1 + 1].second};
                    for (int i = cconti[y1 - 1].first; i <= cconti[y1 + 1].second; i++)
                        cconti[i] = cur;
                }
                else if (y1 + 1 <= n && ccnt[y1 + 1])
                {
                    pii cur = {y1, cconti[y1 + 1].second};
                    for (int i = y1; i <= cconti[y1 + 1].second; i++)
                        cconti[i] = cur;
                }
                else if (y1 - 1 > 0 && ccnt[y1 - 1])
                {
                    pii cur = {cconti[y1 - 1].first, y1};
                    for (int i = cconti[y1 - 1].first; i <= y1; i++)
                        cconti[i] = cur;
                }
                else
                    cconti[y1] = {y1, y1};
            }
            ccnt[y1]++;

            break;
        case 2:
            cin >> x1 >> y1;

            rcnt[x1]--;
            if (rcnt[x1] == 0)
            {
                if (x1 + 1 <= n && x1 - 1 > 0 && rcnt[x1 + 1] && rcnt[x1 - 1])
                {
                    pii l = {rconti[x1 - 1].first, x1-1},
                        r = {x1+1,rconti[x1 + 1].second};
                    for (int i = rconti[x1 - 1].first; i <= x1-1; i++)
                        rconti[i] = l;
                    for (int i = x1+1; i <= rconti[x1 + 1].second; i++)
                        rconti[i] = r;
                }
                else if (x1 + 1 <= n && rcnt[x1 + 1])
                {
                    pii cur = {x1+1, rconti[x1 + 1].second};
                    for (int i = x1+1; i <= rconti[x1 + 1].second; i++)
                        rconti[i] = cur;
                }
                else if (x1 - 1 > 0 && rcnt[x1 - 1])
                {
                    pii cur = {rconti[x1 - 1].first, x1-1};
                    for (int i = rconti[x1 - 1].first; i <= x1-1; i++)
                        rconti[i] = cur;
                }
                else
                    rconti[x1] = {0,0};
            }

            ccnt[y1]--;
            if (ccnt[y1] == 0)
            {
                if (y1 + 1 <= n && y1 - 1 > 0 && ccnt[y1 + 1] && ccnt[y1 - 1])
                {
                    pii l = {cconti[y1 - 1].first, y1-1},
                        r = {y1+1,cconti[y1 + 1].second};
                    for (int i = cconti[y1 - 1].first; i <= y1-1; i++)
                        cconti[i] = l;
                    for (int i = y1+1; i <= cconti[y1 + 1].second; i++)
                        cconti[i] = r;
                }
                else if (y1 + 1 <= n && ccnt[y1 + 1])
                {
                    pii cur = {y1+1, cconti[y1 + 1].second};
                    for (int i = y1+1; i <= cconti[y1 + 1].second; i++)
                        cconti[i] = cur;
                }
                else if (y1 - 1 > 0 && ccnt[y1 - 1])
                {
                    pii cur = {cconti[y1 - 1].first, y1-1};
                    for (int i = cconti[y1 - 1].first; i <= y1-1; i++)
                        cconti[i] = cur;
                }
                else
                    cconti[y1] = {0,0};
            }

            break;
        case 3:
            cin >> x1 >> y1 >> x2 >> y2;

            if((rconti[x1]!=pii(0,0)&&rconti[x1]==rconti[x2])||(cconti[y1]!=pii(0,0)&&cconti[y1]==cconti[y2]))
                cout<<"Yes\n";
            else cout<<"No\n";
            break;
        }
    }
}

int main()
{
    FASTIO
    Solution();
}