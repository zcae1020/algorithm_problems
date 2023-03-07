#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int x, d;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string str[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

void Solution() {
    cin >> x >> d;
    for (int i = 1; i < x; i++) {
        d += day[i];
    }

    cout << str[d % 7];
}

int main() {
    FASTIO
    Solution();
}