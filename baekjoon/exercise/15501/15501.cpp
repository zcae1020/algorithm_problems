#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long

using namespace std;

const int MAX = 1e6;
int n, a[MAX], b[MAX], s;
bool isGood = true;

void Solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[0] == b[i])
            s = i;
    }

    for (int i = 0; i < n; i++)
        if (a[i] != b[(s + i) % n])
        {
            isGood = false;
            break;
        }

    if (isGood)
    {
        cout << "good puzzle";
        return;
    }

    reverse(b, b + n);
    s = n - 1 - s;
    isGood = true;

    for (int i = 0; i < n; i++)
        if (a[i] != b[(s + i) % n])
        {
            isGood = false;
            break;
        }

    if (isGood)
        cout << "good puzzle";
    else
        cout << "bad puzzle";
}

int main()
{
    FASTIO
    Solution();
}