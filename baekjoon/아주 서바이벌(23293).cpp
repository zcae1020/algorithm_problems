//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//typedef struct player {
//	int area = 1;
//	map<int, int> item;
//} Player;
//
//int T, N, logNum, playerNum, op1, op2;
//char inst;
//map<int, Player> players;
//
//vector<int> cheat, banPlayer;
//
//int main() {
//	cin >> T >> N;
//	while (T--) {
//		bool c;
//		cin >> logNum >> playerNum >> inst;
//
//		if (players.count(playerNum) == 0) {
//			Player p;
//			players.insert({ playerNum, p });
//		}
//
//		switch (inst) {
//
//		case 'M':
//			cin >> op1;
//			players[playerNum].area = op1;
//			break;
//		case 'F':
//			cin >> op1;
//			
//			if (players[playerNum].area != op1) cheat.push_back(logNum);
//			if (players[playerNum].item.count(op1)) players[playerNum].item[op1]++;
//			else players[playerNum].item.insert({ op1,1 });
//			
//			break;
//		case 'C':
//			c = false;
//			cin >> op1 >> op2;
//			
//			if (players[playerNum].item.count(op1)) {
//				if (players[playerNum].item[op1]) players[playerNum].item[op1]--;
//				else c = true;
//			}
//			else c = true;
//
//			if (players[playerNum].item.count(op2)) {
//				if (players[playerNum].item[op2]) players[playerNum].item[op2]--;
//				else c = true;
//			}
//			else c = true;
//
//			if (c) cheat.push_back(logNum);
//			
//			break;
//		case 'A':
//			cin >> op1;
//
//			if (players[playerNum].area != players[op1].area) {
//				cheat.push_back(logNum);
//				c = false;
//				for (auto b : banPlayer) 
//					if (b == playerNum) c = true;
//				if (c == false) banPlayer.push_back(playerNum);
//			}
//			break;
//		}
//	}
//
//	sort(cheat.begin(), cheat.end());
//	sort(banPlayer.begin(), banPlayer.end());
//
//	cout << cheat.size() << endl;
//	if (cheat.empty() == 0) {
//		for (auto c : cheat)
//			cout << c << ' ';
//		cout << endl;
//	}
//
//	cout << banPlayer.size();
//	if (banPlayer.empty() == 0) {
//		cout << endl;
//		for (auto b : banPlayer)
//			cout << b << ' ';
//
//	}
//}