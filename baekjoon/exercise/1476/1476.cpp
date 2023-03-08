#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int E, S, M;
int arr[] = {15, 28, 19};
ll num;

void Solution() {
    cin >> E >> S >> M;
    E--, S--, M--;

    num = S;
    while (!(num % arr[0] == E && num % arr[2] == M)) {
        num += arr[1];
    }

    cout << num + 1;
}

int main() {
    FASTIO
    Solution();
}