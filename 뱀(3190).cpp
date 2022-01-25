#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>

using namespace std;

//1초마다 draw하기
// todo inst 입력받기
int N, K, L, map[102][102];//apple:-1,empty:0,wall:1,snake:2
vector<pii> snake, psnake;
queue<int> inst;
queue<int> time;
int ans = 0, dire = 2, isApple;

int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };

void Inst() {
	if (!time.empty() && ans == time.front()) {
		if (!inst.front()) {
			dire--;
			if (dire < 0)
				dire = 3;
		}
		else {
			dire = (++dire) % 4;
		}
		time.pop();
		inst.pop();
	}
}

void snakeClear() {
	for (int i = 0;i < psnake.size();i++)
		map[psnake[i].second][psnake[i].first] = 0;
}

void Draw() {
	for (int i = 0;i < snake.size();i++)
		map[snake[i].second][snake[i].first] = 2;
}

bool Move(int isAp, pii n) { // return: 앞으로 못가면 0, 갈 수 있으면 1
	vector<pii> tmp;
	psnake.clear();
	psnake.insert(psnake.end(), snake.begin(), snake.end());
	if (isAp) {
		tmp.emplace_back(n);
		tmp.insert(tmp.end(), snake.begin(), snake.end());
		snake.clear();
		snake.insert(snake.end(), tmp.begin(), tmp.end());
	}
	else {
		if (map[n.second][n.first] > 0)
			return 0;
		tmp.emplace_back(n);
		tmp.insert(tmp.end(), snake.begin(), snake.end() - 1);
		snake.clear();
		snake.insert(snake.end(), tmp.begin(), tmp.end());
	}
	snakeClear();
	Draw();
	return 1;
}

void setMap() {
	map[1][1] = 2;
	for (int i = 0;i <= N + 1;i++) {
		map[i][0] = 1;
		map[0][i] = 1;
		map[N + 1][i] = 1;
		map[i][N + 1] = 1;
	}
}

int main() {
	snake.emplace_back(1, 1);
	cin >> N >> K;
	setMap();
	int a, b;
	for (int i = 0;i < K;i++) {
		cin >> a >> b;
		map[b][a] = -1;
	}
	cin >> L;
	char c;
	for (int i = 0;i < L;i++) {
		cin >> a >> c;
		time.push(a);
		if (c == 'L')
			inst.push(1);
		else
			inst.push(0);
	}
	while (true) {
		isApple = 0;
		ans++;
		pii next = { snake[0].first + dx[dire],snake[0].second + dy[dire] };
		Inst();
		if (map[next.second][next.first] == -1)
			isApple = 1;
		if (!Move(isApple, next))
			break;
	}
	cout << ans;
}