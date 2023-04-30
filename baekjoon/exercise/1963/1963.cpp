#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxnum = 1e4;

int tc;
string src, dest;
bool isNotPrime[maxnum];

void setIsPrime() {
    for (int i = 2; i < maxnum; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * 2; j < maxnum; j += i) {
                isNotPrime[j] = 1;
            }
        }
    }
}

void Solution() {
    setIsPrime();
    cin >> tc;
    while (tc--) {
        cin >> src >> dest;
        queue<pair<string, int>> q;
        map<string, bool> visited;
        int ans = -1;

        q.push({src, 0});
        visited[src] = 1;
        while (!q.empty()) {
            string cur = q.front().fs;
            int cnt = q.front().sd;
            q.pop();

            if (cur == dest) {
                ans = cnt;
                break;
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 10; j++) {
                    if ((i == 0 && j == 0) || (cur[i] == j))
                        continue;

                    string next = cur;
                    next[i] = j + '0';

                    int nnum = stoi(next);

                    if (!isNotPrime[nnum] && !visited[next]) {
                        q.push({next, cnt + 1});
                        visited[next] = 1;
                    }
                }
            }
        }

        if (ans == -1) {
            cout << "Impossible\n";
            continue;
        }
        cout << ans << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}