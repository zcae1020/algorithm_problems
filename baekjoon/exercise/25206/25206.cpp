#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string n, s1, s2;
int s;
double score;

string type[] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
double num[] = {4.5, 4, 3.5, 3, 2.5, 2, 1.5, 1, 0};

void Solution() {
    while (cin >> n >> s1 >> s2) {
        if (cin.eof()) {
            break;
        }

        if (s2 == "P")
            continue;

        for (int i = 0; i < 9; i++) {
            if (s2 == type[i]) {
                s += s1[0] - '0';
                score += num[i] * (s1[0] - '0');
                break;
            }
        }
    }

    cout << score / s;
}

int main() {
    FASTIO
    Solution();
}
