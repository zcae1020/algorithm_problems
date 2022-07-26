#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int N, Q, C, CAP[2001], cur, cache;
deque<int> B, F;
char inst;

void Solution()
{
    cin >> N >> Q >> C;
    for (int i = 1; i <= N; i++)
        cin >> CAP[i];
    while (Q--)
    {
        cin >> inst;
        switch (inst)
        {
        case 'B':
            if (B.size())
            {
                F.push_back(cur);
                cur = B.back();
                B.pop_back();
            }
            break;
        case 'F':
            if (F.size())
            {
                B.push_back(cur);
                cur = F.back();
                F.pop_back();
            }
            break;
        case 'A':
            while (F.size())
            {
                cache -= CAP[F.back()];
                F.pop_back();
            }

            if (cur)
                B.push_back(cur);
            cin >> cur;
            cache += CAP[cur];

            while (cache > C)
            {
                cache -= CAP[B.front()];
                B.pop_front();
            }
            break;
        case 'C':
            if (B.size())
            {
                deque<int> tmp;
                int t = B.front();
                B.pop_front();

                while (B.size())
                {
                    if (t != B.front())
                    {
                        tmp.push_back(t);
                        t = B.front();
                    }
                    else
                        cache -= CAP[t];
                    B.pop_front();
                }

                tmp.push_back(t);
                while (tmp.size())
                {
                    B.push_back(tmp.front());
                    tmp.pop_front();
                }
            }
            break;
        }
    }

    cout << cur << '\n';
    if (B.size())
    {
        while (B.size())
        {
            cout << B.back() << ' ';
            B.pop_back();
        }
    }
    else
        cout << -1;
    cout << '\n';

    if (F.size())
    {
        while (F.size())
        {
            cout << F.back() << ' ';
            F.pop_back();
        }
    }
    else
        cout << -1;
}

int main()
{
    FASTIO
    Solution();
}