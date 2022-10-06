#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int X, N, sum;

void Solution()
{
    cin >> X >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }

    cout << (X == sum ? "Yes" : "No");
}

int main()
{
    FASTIO
    Solution();
}