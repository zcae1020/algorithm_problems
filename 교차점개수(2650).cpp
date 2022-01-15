#include <iostream>
#include <vector>

using namespace std;

int N, point[51][4], res = 0;

//void swap(int idx) {
//	vector<int> tmp;
//	tmp.push_back(vertex[idx][0]);
//	tmp.push_back(vertex[idx][1]);
//	tmp.push_back(vertex[idx][2]);
//	tmp.push_back(vertex[idx][3]);
//	vertex[idx][0] = tmp[2];
//	vertex[idx][1] = tmp[3];
//	vertex[idx][2] = tmp[0];
//	vertex[idx][3] = tmp[1];
//}

int isHigh(vector<int> twoPoint) {
	if (twoPoint[0] == twoPoint[2]) { //같은 변
		if (twoPoint[0] == 1 || twoPoint[0] == 2 || twoPoint[1] == twoPoint[3])
			return 3; //높이 같음
		else if (twoPoint[1] > twoPoint[3])
			return 1;
		else
			return 2;
	}
	else { //다른 변

	}
	
}

int isLeft(vector<int> twoPoint) {

}

int checkCollision(int idx) {
	int ret = 0, v1, v2;

	for (int i = 0;i < N / 2;i++) {
		
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0;i < N / 2;i++) {
		for (int j = 0;j < 4;j++) {
			cin >> point[i][j];
		}
	}

	int tmp, mx = 0;
	for (int i = 0;i < N / 2;i++) {
		tmp = checkCollision(i);
		if (tmp > mx)
			mx = tmp;
		res += tmp;
	}

	cout << res / 2 << '\n' << mx;
}