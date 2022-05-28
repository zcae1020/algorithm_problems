#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int MAX = 2e5 + 10;

int n, arr[MAX], ansl, ansr;
ll mx;

void Input()
{
    cin >> n;

    ansl = n, ansr = 0;
    mx = 0;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void getAns(int l, int r)
{
    int a, b, cnt = 0, neg = 0;
    bool f = false;

    for (int i = l; i < r; i++)
    {
        if (abs(arr[i]) == 2)
            cnt++;
        if (arr[i] < 0)
        {
            if (!f)
            {
                a = i + 1;
                f = true;
            }
            neg++;
            b = i;
        }
    }

    if (neg % 2)
    {
        int ca = 0, cb = 0;
        for (int i = a; i < r; i++)
            if (abs(arr[i]) == 2)
                ca++;
        for (int i = l; i < b; i++)
            if (abs(arr[i]) == 2)
                cb++;

        if (ca > cb)
        {
            if (mx < ca)
            {
                ansl = a;
                ansr = n - r;
                mx = ca;
            }
        }
        else
        {
            if (mx < cb)
            {
                ansl = l;
                ansr = n - b;
                mx = cb;
            }
        }
    }
    else //+
    {
        if (mx < cnt)
        {
            ansl = l;
            ansr = n - r;
            mx = cnt;
        }
    }
}

void Solution()
{
    int neg = 0;
    vector<int> zero;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg++;
        if (arr[i] == 0)
            zero.push_back(i);
    }

    if (zero.empty())
    {
        if (neg % 2)
        {
            getAns(0, n);
            cout << ansl << ' ' << ansr << '\n';
        }
        else
            cout << 0 << ' ' << 0 << '\n';
    }
    else
    {
        int l = 0;
        zero.push_back(n);
        for (auto r : zero)
        {
            getAns(l, r);
            l = r + 1;
        }
        cout << ansl << ' ' << ansr << '\n';
    }
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