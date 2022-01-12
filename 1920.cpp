#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();

	int N, M, arr[100005], input, flag;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> input;
		flag = 1;
		for (int j = 0;j < N;j++) {
			if (arr[j] == input) {
				printf("1\n");
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("0\n");
	}

}