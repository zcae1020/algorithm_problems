//#include <iostream>
//
//using namespace std;
//
//int input[10], map[33], answer; // 0:start, 21:finsh
//
//int isNext(int idx, int move) {
//	int nidx, nmove;
//
//	if (move == 0) return idx;
//
//	if (idx == 5)
//		return isNext(22, move - 1);
//	else if (idx == 10)
//		return isNext(25, move - 1);
//	else if (idx == 15)
//		return isNext(27, move - 1);
//	else if (idx >= 22) {
//		if (idx < 25) {
//			if (idx + move > 24) {
//				nmove = move - (25 - idx);
//				nidx = 30;
//				return isNext(nidx, nmove);
//			}
//			else {
//				return idx + move;
//			}
//		}
//		else if (idx < 27) {
//			if (idx + move > 26) {
//				nmove = move - (27 - idx);
//				nidx = 30;
//				return isNext(nidx, nmove);
//			}
//			else {
//				return idx + move;
//			}
//		}
//		else if (idx < 30) {
//			if (idx + move > 29) {
//				nmove = move - (30 - idx);
//				nidx = 30;
//				return isNext(nidx, nmove);
//			}
//			else {
//				return idx + move;
//			}
//		}
//		else if (idx < 33) {
//			if (idx + move > 32) {
//				nmove = move - (33 - idx);
//				nidx = 20;
//				return isNext(nidx, nmove);
//			}
//			else {
//				return idx + move;
//			}
//		}
//	}
//	else {
//		nidx = idx + move;
//		if (nidx > 20) return 21;
//		return nidx;
//	}
//}
//
//int getAnswer(int n) {
//	if (n == 21 || n == 0) return 0;
//
//	const int score[11] = {
//		13,16,19,22,24,28,27,26,25,30,35
//	};
//
//	if (n < 22) return n * 2;
//	else return score[n - 22];
//}
//
//void DFS(int inputIdx, int ans) {
//	if (inputIdx == 10) {
//		answer = max(answer, ans);
//		return;
//	}
//	for (int i = 0; i < 33; i++) {
//		if (i == 21) continue;
//		if (map[i]) {
//			int n = isNext(i, input[inputIdx]);
//			if (n == 21 || map[n] == 0) {
//				map[i]--, map[n]++;
//				DFS(inputIdx + 1, ans + getAnswer(n));
//				map[i]++, map[n]--;
//			}
//		}
//	}
//}
//
//int main() {
//	for (int i = 0; i < 10; i++) cin >> input[i];
//	map[0] = 4;
//
//	DFS(0, 0);
//	cout << answer;
//}