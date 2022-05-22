#include <iostream>
#include <string>

using namespace std;

string X;
int ans;
bool isThree;

void Input() {
    cin>>X;
}

void getAns(int a, int num){
    if(num<10){
        ans=a;
        if(num==3||num==6||num==9) isThree=true;
        return;
    }
    else{
        int nnum=0;
        while(num){
            nnum+=num%10;
            num/=10;
        }
        getAns(a+1, nnum);
    }
}

void Solution() {
    if(X.size()==1){
        cout<<0<<'\n';
        if(X[0]=='3'||X[0]=='6'||X[0]=='9') cout<<"YES";
        else cout<<"NO";
        return;
    }

    int num=0;
    for(auto x:X)
        num+=(x-'0');
    
    getAns(1, num);

    cout<<ans<<'\n';
    if(isThree) cout<<"YES";
    else cout<<"NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}

