//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//class person {
//
//public:
//	string name;
//	int year;
//	int month;
//	int day;
//
//	person(string name, int year, int month, int day) {
//		this->name = name;
//		this->year = year;
//		this->month = month;
//		this->day = day;
//	}
//};
//
//vector<person> v;
//
//bool compare(person p1, person p2) {
//	if (p1.year != p2.year)
//		return p1.year > p2.year;
//	else if (p1.month != p2.month)
//		return p1.month > p2.month;
//	return p1.day > p2.day;
//}
//
//int main() {
//	int N;
//	char str[20];
//	int d, m, y;
//	cin >> N;
//	for (int i = 0;i < N;i++) {
//		cin >> str >> d >> m >> y;
//		string tmp(str);
//		v.push_back(person(tmp, y, m, d));
//	}
//	sort(v.begin(), v.end(), compare);
//	cout << v[0].name.c_str() << endl << v[N - 1].name.c_str();
//}