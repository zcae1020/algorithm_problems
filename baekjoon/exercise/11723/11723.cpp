#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int m, x;
string str;
set<int> s;

// 숫자가 20까지만 있기에 비트마스킹으로도 가능

void Solution() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str == "add") {
            cin >> x;
            s.insert(x);
        } else if (str == "remove") {
            cin >> x;
            s.erase(x);
        } else if (str == "check") {
            cin >> x;
            cout << s.count(x) << '\n';
        } else if (str == "toggle") {
            cin >> x;
            if (s.count(x)) {
                s.erase(x);
            } else {
                s.insert(x);
            }
        } else if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                s.insert(i);
            }
        } else if (str == "empty") {
            s.clear();
        }
    }
}

int main() {
    FASTIO
    Solution();
}