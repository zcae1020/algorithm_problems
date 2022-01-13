#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int x1, x2, y1, y2, visited[102][102], sum = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0;i < 4;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1;j < x2;j++) {
			for (int k = y1;k < y2;k++) {
				if (visited[k][j])
					continue;
				sum++;
				visited[k][j] = 1;
			}
		}
	}
	cout << sum;
}