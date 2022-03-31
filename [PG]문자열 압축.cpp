//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int getAnswer(string s, int cut) {
//    string curS, nextS, ans;
//    int cnt = 1;
//
//    for (int i = 0; i < cut; i++) curS.push_back(s[i]);
//
//    for (int i = cut, j, curC; i < s.size();) {
//
//        curC = cut;
//        nextS.clear();
//
//        while (i < s.size() && curC--) nextS.push_back(s[i++]);
//
//        if (curS.compare(nextS) == 0) cnt++;
//        else {
//            if (cnt != 1) ans.append(to_string(cnt));
//            ans.append(curS);
//            cnt = 1;
//        }
//
//        curS.swap(nextS);
//    }
//
//    if (cnt != 1) ans.append(to_string(cnt));
//    ans.append(curS);
//
//    return ans.size();
//}
//
//int solution(string s) {
//    if (s.size() == 1) return 1;
//
//    int answer = 1000;
//    for (int i = 1; i <= s.size() / 2; i++) {
//        answer = min(answer, getAnswer(s, i));
//    }
//    return answer;
//}
//
//int main() {
//    int T;
//    string s;
//    cin >> T;
//
//    while (T--) {
//        cin >> s;
//        cout << solution(s) << '\n';
//    }
//}