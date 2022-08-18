#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define x first
#define y second

using namespace std;

int N, M, cnt[10001];
vector<int> arr, v;

void dfs(int idx)
{
    if (v.size() == M)
    {
        for (auto a : v)
            cout << a << ' ';
        cout << '\n';
    }
    if (idx == arr.size())
        return;

    for (int i = idx; i < arr.size(); i++)
    {
        if (cnt[arr[i]])
        {
            cnt[arr[i]]--;
            v.push_back(arr[i]);
            dfs(idx);
            cnt[arr[i]]++;
            v.pop_back();
        }
    }
}

void Solution()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (!cnt[x])
            arr.push_back(x);
        cnt[x]++;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cnt[arr[i]]--;
        v.push_back(arr[i]);
        dfs(0);
        cnt[arr[i]]++;
        v.pop_back();
    }
}

int main()
{
    FASTIO
    Solution();
}