//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, arrN, inst[50], insts[100][50], switc[50];
//vector<int> res;
//int to[5] = { 0,3,4,1,2 };
//
//void makeSwitc(int idx) {
//	int tmp[50];
//	for (int i = 0;i < N;i++)
//		tmp[i] = to[insts[idx][i]];
//	for (int i = 0;i < N;i++)
//		switc[i] = tmp[N - i - 1];
//}
//
//bool isEqual(int idx) {
//	makeSwitc(idx);
//	int start = inst[0];
//	int flag;
//	for (int i = 0;i < N;i++) {
//		flag = 1;
//		if (insts[idx][i] == start) {
//			for (int j = 1;j < N;j++) {
//				if (insts[idx][(i + j) % N] != inst[j]) {
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)
//				return true;
//		}
//	}
//	for (int i = 0;i < N;i++) {
//		flag = 1;
//		if (switc[i] == start) {
//			for (int j = 1;j < N;j++) {
//				if (switc[(i + j) % N] != inst[j]) {
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)
//				return true;
//		}
//	}
//	return false;
//}
//
//
//int main() {
//	cin >> N;
//	for (int i = 0;i < N;i++)
//		cin >> inst[i];
//
//	cin >> arrN;
//	for (int i = 0;i < arrN;i++) {
//		for (int j = 0;j < N;j++) {
//			cin >> insts[i][j];
//		}
//		if (isEqual(i))
//			res.emplace_back(i);
//	}
//
//	cout << res.size() << endl;
//	for (int i = 0;i < res.size();i++) {
//		for (int j = 0;j < N;j++)
//			cout << insts[res[i]][j] << ' ';
//		cout << endl;
//	}
//}