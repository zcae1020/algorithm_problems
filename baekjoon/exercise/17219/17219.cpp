#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M;
map<string, string> m;
string s1, s2;

void Solution() {
    cin >> N >> M;
    while (N--) {
        cin >> s1 >> s2;
        m[s1] = s2;
    }

    while (M--) {
        cin >> s1;
        cout << m[s1] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}