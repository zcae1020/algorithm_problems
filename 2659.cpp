#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int visited[10000];

int makeClockNum(vector<int> num, int type) {
	int clockNum;
	switch(type) {
		case 0:
			clockNum = 1000 * num[0] + 100 * num[1] + 10 * num[2] + num[3];
			break;
		case 1:
			clockNum = 1000 * num[1] + 100 * num[2] + 10 * num[3] + num[0];
			break;
		case 2:
			clockNum = 1000 * num[2] + 100 * num[3] + 10 * num[0] + num[1];
			break;
		case 3:
			clockNum = 1000 * num[3] + 100 * num[0] + 10 * num[1] + num[2];
			break;
	}
	return clockNum;
}

int findClockNum(vector<int> num) {
	int min = 10000, tmp;
	for (int i = 0;i < 4;i++) {
		tmp = makeClockNum(num, i);
		visited[tmp - 1111] = 1;
		if (tmp < min)
			min = tmp;
	}
	return min;
}

int main() {
	vector<int> arr(4);
	int myCN, order = 0;
	for (int i = 0;i < 4;i++)
		cin >> arr[i];

	myCN = findClockNum(arr);
	memset(visited, 0, sizeof(visited));

	vector<int> tmp;
	for (int a = 1;a < 10;a++) {
		for (int b = 1;b < 10;b++) {
			for (int c = 1;c < 10;c++) {
				for (int d = 1;d < 10;d++) {
					tmp.clear();
					tmp.push_back(a);
					tmp.push_back(b);
					tmp.push_back(c);
					tmp.push_back(d);
					if (visited[makeClockNum(tmp, 0) - 1111])
						continue;
					order++;
					int temp = findClockNum(tmp);
					if (myCN == temp) {
						cout << order;
						return 0;
					}
				}
			}
		}
	}
}