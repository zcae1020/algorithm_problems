#include <iostream>
#include <vector>

using namespace std;

int n;
bool isYes;
vector<int> a,b,cnt;

void Input() {
    cin>>n;

    cnt.clear();
    a.clear();
    b.clear();
    cnt.resize(n+1);
    isYes = true;

    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        b.push_back(tmp);
    }
}

void Solution() {
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(a[aidx])
            cnt[a[aidx++]]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        Input();
        Solution();
        if(isYes) cout<<"YES\n";
        else cout<<"NO\n";
    }
}