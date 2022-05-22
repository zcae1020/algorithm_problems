//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <tuple>
//#define pii pair<int,int>
//
//using namespace std;
//
//typedef struct shark {
//	int speed;
//	int direction;
//	int size;
//}Shark;
//
//Shark map[101][101];
//Shark nmap[101][101];
//
//int R, C, M, ans = 0;
//int dc[5] = { 0,0,0,1,-1 }, dr[5] = { 0,-1,1,0,0 };
//
//void move(int r, int c) {
//	Shark cs = map[r][c];
//	int cr = r, cc = c, cspeed = cs.speed;
//	while (cspeed) {
//		switch (cs.direction) {
//		case 1: //위
//			if (cspeed >= cr - 1) {
//				cs.direction = 2;
//				cspeed -= (cr - 1);
//				cr = 1;
//			}
//			else {
//				cr += dr[cs.direction] * cspeed;
//				cspeed = 0;
//			}
//			break;
//		case 2: //아래
//			if (cspeed >= R - cr) {
//				cs.direction = 1;
//				cspeed -= (R - cr);
//				cr = R;
//			}
//			else {
//				cr += dr[cs.direction] * cspeed;
//				cspeed = 0;
//			}
//			break;
//		case 3: //오른쪽
//			if (cspeed >= C - cc) {
//				cs.direction = 4;
//				cspeed -= (C - cc);
//				cc = C;
//			}
//			else {
//				cc += dc[cs.direction] * cspeed;
//				cspeed = 0;
//			}
//			break;
//		case 4: //왼쪽
//			if (cspeed >= cc - 1) {
//				cs.direction = 3;
//				cspeed -= (cc - 1);
//				cc = 1;
//			}
//			else {
//				cc += dc[cs.direction] * cspeed;
//				cspeed = 0;
//			}
//			break;
//		}
//	}
//
//	if (nmap[cr][cc].size) {
//		if (nmap[cr][cc].size < cs.size) {
//			nmap[cr][cc].direction = cs.direction;
//			nmap[cr][cc].speed = cs.speed;
//			nmap[cr][cc].size = cs.size;
//		}
//	}
//	else {
//		nmap[cr][cc].direction = cs.direction;
//		nmap[cr][cc].speed = cs.speed;
//		nmap[cr][cc].size = cs.size;
//	}
//	map[r][c].direction = 0;
//	map[r][c].size = 0;
//	map[r][c].speed = 0;
//}
//
//void nmap2map() {
//	for (int i = 1;i <= R;i++) {
//		for (int j = 1;j <= C;j++) {
//			if (nmap[i][j].size) {
//				map[i][j].direction = nmap[i][j].direction;
//				map[i][j].size = nmap[i][j].size;
//				map[i][j].speed = nmap[i][j].speed;
//				nmap[i][j].direction = 0;
//				nmap[i][j].size = 0;
//				nmap[i][j].speed = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> R >> C >> M;
//	for (int i = 0;i < M;i++) {
//		int r, c, s, d, z;
//		cin >> r >> c >> s >> d >> z;
//		map[r][c].speed = s;
//		map[r][c].direction = d;
//		map[r][c].size = z;
//	}
//	for (int i = 1;i <= C;i++) {
//		for (int j = 1;j <= R;j++) {
//			if (map[j][i].size) {
//				ans += map[j][i].size;
//				map[j][i].direction = map[j][i].size = map[j][i].speed = 0;
//				break;
//			}
//		}
//
//		for (int j = 1;j <= R;j++) {
//			for (int k = 1;k <= C;k++) {
//				if (map[j][k].size)
//					move(j, k);
//			}
//		}
//
//		nmap2map();
//	}
//	cout << ans;
//}