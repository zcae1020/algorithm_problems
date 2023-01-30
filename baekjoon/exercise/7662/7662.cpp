#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int,int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t,n;
ll b,num;
string a;

void Solution() {
    cin>>t;
    while(t--) {
        priority_queue<ll> mx,mn;
        map<ll,ll> m;

        cin>>n;
        while(n--) {
            cin>>a>>b;
            if(a == "I") {
                m[b]++;
                mx.push(b);
                mn.push(-b);
            }
            else {
                bool flag = false;
                if(b==1) {
                    while(!mx.empty()) {
                        num = mx.top();
                        mx.pop();   
                        if(m[num]) {
                            flag = true;
                            break;
                        }
                    }
                }
                else {
                    while(!mn.empty()) {
                        num = -mn.top();
                        mn.pop();   
                        if(m[num]) {
                            flag = true;
                            break;
                        }
                    }
                }

                if(flag) {
                    m[num]--;
                }
            }
        }

        vector<int> nums;

        for(auto p:m) {
            if(p.sd) {
                nums.push_back(p.fs);
            }
        }

        if(nums.empty()) {
            cout<<"EMPTY\n";
            continue;
        }

        sort(nums.begin(), nums.end());

        cout<<nums.back()<<' '<<nums.front()<<'\n';
    }
}

int main() {
    FASTIO
    Solution();
}