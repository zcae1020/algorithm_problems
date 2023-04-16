#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, ans;
map<string, int> m;

string num;
int strike, ball;
bool visited[10];

bool isEqual(string cur) {
    int cs = 0, cb = 0;
    for (auto c : cur) {
        int idx = num.find(c);
        if (idx != -1) {
            if (cur[idx] == c) {
                cs++;
            } else {
                cb++;
            }
        }
    }

    return cs == strike && cb == ball;
}

void addAble(string cur) {
    if (cur.size() == 3) {
        if (isEqual(cur)) {
            m[cur]++;
        }
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (!visited[i]) {
            cur.push_back(i + '0');
            visited[i] = true;
            addAble(cur);
            visited[i] = false;
            cur.pop_back();
        }
    }
}

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num >> strike >> ball;

        addAble("");
    }

    for (auto p : m) {
        ans += p.sd == n;
    }
    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
