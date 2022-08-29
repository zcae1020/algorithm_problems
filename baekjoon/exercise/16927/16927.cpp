#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M, R, A[300][300];

void rotate(int idx)
{
    int curN = N - 2 * idx, curM = M - 2 * idx;
    int len = curN * 2 + curM * 2 - 4, cnt = (len - R % len) % len;

    vector<int> v;

    int x = idx, y = idx;
    for (; x < idx + curN - 1; x++)
        v.push_back(A[x][y]);
    for (; y < idx + curM - 1; y++)
        v.push_back(A[x][y]);
    for (; x > idx; x--)
        v.push_back(A[x][y]);
    for (; y > idx; y--)
        v.push_back(A[x][y]);

    x = idx, y = idx;
    for (; x < idx + curN - 1; x++, cnt = (cnt + 1) % len)
        A[x][y] = v[cnt];
    for (; y < idx + curM - 1; y++, cnt = (cnt + 1) % len)
        A[x][y] = v[cnt];
    for (; x > idx; x--, cnt = (cnt + 1) % len)
        A[x][y] = v[cnt];
    for (; y > idx; y--, cnt = (cnt + 1) % len)
        A[x][y] = v[cnt];
}

void Solution()
{
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < min(N, M) / 2; i++)
        rotate(i);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << A[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    FASTIO
    Solution();
}