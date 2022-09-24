#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> full;

void makefull(){
    for(int i=2;i<256;i*=2){
        full.push_back(i-1);
    }
}

string dec2bin(long long num){
    string ret;
    while(num){
        ret.push_back((num%2)+'0');
        num/=2;
    }

    for(auto f:full){
        if(ret.size()==f) break;
        if(ret.size()<f){
            int s = ret.size();
            for(int i=0;i<f-s;i++)
                ret.push_back('0');
            break;
        }
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

bool check(string s){
    if(s.size()==1)
        return 1;
    if(s[s.size()/2]=='0')
        return 0;

    bool flag = 1;
    for(auto c:s){
        if(c=='1'){
            flag = 0;
            break;
        }
    }
    if(flag) return 1;
    
    return check(s.substr(0, s.size()/2))&&check(s.substr(s.size()/2+1, s.size()/2));
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    makefull();

    for(auto n:numbers){
        bool c = check(dec2bin(n));
        answer.push_back(c?1:0);
    }

    return answer;
}

vector<long long> n;

int main(){
    n.push_back(63);
    n.push_back(5);
    solution(n);
}