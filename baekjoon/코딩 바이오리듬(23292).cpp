//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#define pii pair<string, int>
//
//using namespace std;
//
//string birth;
//int N;
//vector<pii> v;
//
//bool comp(pii p1, pii p2) {
//	if (p1.second == p2.second)
//		return p1.first.compare(p2.first) < 0 ? true : false;
//	return p1.second > p2.second;
//}
//
//int bioRythm(string coding) {
//	int y, m, d, idx, bn, cn;
//	y = m = d = idx = 0;
//	for (; idx < 4; idx++) {
//		bn = birth[idx] - '0';
//		cn = coding[idx] - '0';
//		y += (bn - cn) * (bn - cn);
//	}
//	for (; idx < 6; idx++) {
//		bn = birth[idx] - '0';
//		cn = coding[idx] - '0';
//		m += (bn - cn) * (bn - cn);
//	}
//	for (; idx < 8; idx++) {
//		bn = birth[idx] - '0';
//		cn = coding[idx] - '0';
//		d += (bn - cn) * (bn - cn);
//	}
//	return y * m * d;
//}
//
//int main() {
//	cin >> birth >> N;
//	for (int i = 0; i < N; i++) {
//		string c;
//		cin >> c;
//		v.push_back(make_pair(c, bioRythm(c)));
//	}
//
//	sort(v.begin(), v.end(), comp);
//	cout << v[0].first;
//}