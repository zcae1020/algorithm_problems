#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

struct student {
    string name;
    int kor, eng, math;

    // operator<(struct student s) {
    //     if (this->kor == s.kor && this->eng == s.eng && this->math == s.math) {
    //         return this->name < s.name;
    //     }

    //     if (this->kor == s.kor && this->eng == s.eng) {
    //         return this->math > s.math;
    //     }

    //     if (this->kor == s.kor) {
    //         return this->eng < s.eng;
    //     }

    //     return this->kor > s.kor;
    // }
};

const int maxn = 1e5;

int n;
struct student Student[maxn];

bool cmp(struct student a, struct student b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) {
        return a.name < b.name;
    }

    if (a.kor == b.kor && a.eng == b.eng) {
        return a.math > b.math;
    }

    if (a.kor ==b.kor) {
        return a.eng < b.eng;
    }

    return a.kor > b.kor;
}

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Student[i].name >> Student[i].kor >> Student[i].eng >>
            Student[i].math;
    }

    sort(Student, Student + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << Student[i].name << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}