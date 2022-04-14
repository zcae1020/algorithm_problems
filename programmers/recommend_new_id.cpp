#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    
    //1
    for(int i=0;i<new_id.size();i++){
        if('A'<=new_id[i]&&new_id[i]<='Z')
            new_id[i]=new_id[i]-'A'+'a';
    }
    
    //2
    for(int i=0;i<new_id.size();i++){
        char cur = new_id[i];

        if(('a'<=cur&&cur<='z')||
            ('0'<=cur&&cur<='9')||
            cur=='-'||cur=='_'||cur=='.') continue;
        
        new_id.erase(i,1);
        i--;
    }

    //3
    bool flag=false;
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]=='.'){
            if(flag) new_id.erase(i,1), i--;
            else flag=true;
        }
        else flag=false;
    }

    //4
    if(new_id[0]=='.') new_id.erase(0,1);
    if(new_id[new_id.size() - 1]=='.') new_id.erase(new_id.size()-1,1);

    //5
    if(new_id.empty()) new_id.insert(new_id.end(), 'a');
    
    //6
    if(new_id.size()>=16){
        new_id.erase(15,new_id.size() - 15);
        if(new_id[new_id.size()-1]=='.') new_id.erase(new_id.size()-1,1);
    }

    //7
    if(new_id.size()<=2){
        while(new_id.size()<3){
            new_id.insert(new_id.end(),new_id[new_id.size()-1]);
        }
    }

    string answer(new_id, 0, new_id.size());
    return answer;
}

int main(){
    string input;
    cin>>input;
    cout<<solution(input);
}