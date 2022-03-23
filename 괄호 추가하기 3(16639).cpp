//#include <iostream>
//#include <algorithm>
//#include <climits>
//#define pii pair<int,int>
//
//using namespace std;
//
//char input[20];
//int N, maxDP[10][10], minDP[10][10];
//
//void Input() {
//	cin >> N >> input;
//
//	for (int i = 0; i <= N / 2; i++) {
//		for (int j = 0; j <= N / 2; j++) {
//			maxDP[i][j] = INT_MIN;
//			minDP[i][j] = INT_MAX;
//		}
//	}
//
//	for (int i = 0; i < N; i+=2) maxDP[i / 2][i / 2] = minDP[i / 2][i / 2] = input[i] - '0';
//}
//
//int cal(int op1, int op2, char i) {
//	if (i == '+') return op1 + op2;
//	else if (i == '-') return op1 - op2;
//	else if (i == '*') return op1 * op2;
//}
//
//void Solution() {
//	for (int i = 1; i <= N / 2; i++) {
//		for (int j = i - 1; j >= 0; j--) {
//			//DP[j][i]
//			for (int k = 0; k < i - j; k++) {
//				char curInst = input[(j + k) * 2 + 1];
//
//				int candidate[4] = {
//					cal(maxDP[j][j + k],maxDP[j + 1 + k][i],curInst),
//					cal(maxDP[j][j + k],minDP[j + 1 + k][i],curInst),
//					cal(minDP[j][j + k],maxDP[j + 1 + k][i],curInst),
//					cal(minDP[j][j + k],minDP[j + 1 + k][i],curInst),
//				};
//
//				sort(candidate, candidate + 4);
//
//				maxDP[j][i] = max(maxDP[j][i], candidate[3]);
//				minDP[j][i] = min(minDP[j][i], candidate[0]);
//			}
//		}
//	}
//
//	cout << maxDP[0][N / 2];
//}
//
//int main() {
//	Input();
//	Solution();
//}