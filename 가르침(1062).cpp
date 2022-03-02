//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//bool alpa[26];
//int N, K;
//string input;
//char antic[5] = { 'a','n','t','i','c' };
//vector<vector<char>> v;
//
//int canRead() {
//	int ret = 0, flag;
//	for (int i = 0;i < v.size();i++) {
//		flag = 1;
//		for (int j = 0;j < v[i].size();j++) {
//			if (!alpa[v[i][j] - 'a']) {
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//			ret++;
//	}
//	return ret;
//}
//
//int ans(int rest, int idx) {
//	int ret = 0;
//	if (rest == 0)
//		return canRead();
//
//	for (int i = idx;i < 26;i++) {
//		if (!alpa[i]) {
//			alpa[i] = true;
//			ret = max(ret, ans(rest - 1, i + 1));
//			alpa[i] = false;
//		}
//	}
//	return ret;
//}
//
//int main() {
//	cin >> N >> K;
//	K -= 5;
//	if (K < 0) {
//		cout << 0;
//		return 0;
//	}
//	for (int i = 0;i < 5;i++)
//		alpa[antic[i] - 'a'] = true;
//
//	vector<char> tmp;
//	while (N--) {
//		cin >> input;
//		tmp.clear();
//
//		for (int i = 4;i < input.size() - 4;i++) {
//			if (alpa[input[i] - 'a'])
//				continue;
//			tmp.push_back(input[i]);
//			alpa[input[i] - 'a'] = true;
//		}
//
//		for (int i = 0;i < tmp.size();i++)
//			alpa[tmp[i] - 'a'] = false;
//
//		if (tmp.size() > K)
//			continue;
//
//		v.push_back(tmp);
//	}
//
//	cout << ans(K, 0);
//}