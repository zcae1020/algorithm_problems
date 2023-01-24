#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 100, maxl = 20;

int n;
string num[maxn];
int alpha[maxl][maxl], alToNum[maxl], shouldZeroCnt;
set<int> shouldNonzero;
int currentNum = 9;

ll getSum() {
    ll ret = 0;
    for(int i=0;i<n;i++) {
        ll number = 0;
        for(ll j=num[i].size()-1,k=1;j>=0;j--,k*=10) {
            number+=alToNum[num[i][j]-'A']*k;
        }
        ret+=number;
    }
    return ret;
}

void getZero() {
    for(int i=0;i<maxl;i++) {
        if(shouldNonzero.count(i) == 0 && alToNum[i] == -1) {
            alToNum[i] = 0;
            return;
        }
    }
}

bool cmp(int a, int b) {
    for(int i=maxl;i>=0;i--) {
        if(alpha[a][i] != alpha[b][i]) {
            return alpha[a][i] > alpha[b][i];
        }
    }

    return true;
}

void Solution() {
    memset(alToNum, -1, sizeof(alToNum));

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>num[i];
        for(int j=num[i].size()-1;j>=0;j--) {
            alpha[num[i][j]-'A'][num[i].size()-1-j]++;
        }
        shouldNonzero.insert(num[i][0] - 'A');
    }

    shouldZeroCnt = 9 - shouldNonzero.size();

    for(int i=maxl;i>=0;i--) { // 자릿수
        vector<int> idxs;
        int mx = -1;

        if(!shouldZeroCnt) {
            shouldZeroCnt--;
            getZero();
        }

        for(int j=0;j<maxl;j++) {
            if(alToNum[j]!=-1 || !alpha[j][i]) {
                continue;
            }

            if(alpha[j][i] > mx) {
                idxs.clear();
                mx = alpha[j][i];
                idxs.push_back(j);
            }
            else if(alpha[j][i] == mx) {
                idxs.push_back(j);
            }
        }

        sort(idxs.begin(), idxs.end(), cmp);

        if(mx != -1) {
            for(auto idx:idxs) {
                alToNum[idx] = currentNum--;
                shouldZeroCnt = shouldNonzero.count(idx) ? shouldZeroCnt : shouldZeroCnt - 1;
            }
        }
    }

    cout<<getSum();
}

int main() {
    FASTIO
    Solution();
}