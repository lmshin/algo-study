#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int graph[51][51] = { 0 };
int answer = 0;

//북동남서
int dr[4][4] = {
	{ 0, 1, 0, -1 }, //북 서 남 동 북
	{ -1 ,0 ,1, 0 }, //동 북 서 남 동
	{ 0, -1, 0, 1 }, //남 동 북 서 남
	{ 1, 0, -1, 0 }, //서 남 동 북 서
};

int dc[4][4] = {
	{ -1, 0, 1, 0 }, //북 서 남 동 북
	{ 0, -1, 0, 1 }, //동 북 서 남 동
	{ 1, 0, -1, 0 }, //남 동 북 서 남
	{ 0, 1, 0, -1 }, //서 남 동 북 서
};

struct pos {
	int r;
	int c;
	int dir;
};

int main() {
	int n, m, r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	queue<pos> q;
	q.push({ r,c,d });
	int nexR;
	int nexC;
	int curR;
	int curC;
	int nexdir;
	bool isPushed;
	while (!q.empty()) {
		isPushed = false;
		curR = q.front().r;
		curC = q.front().c;
		int dir = q.front().dir;

		if (graph[curR][curC] == 0) {
			graph[curR][curC] = 2;
			answer++;
		}

		q.pop();

		//현재 가리키고 있는 방향을 기준으로 왼쪽으로 회전해야함
		for (int i = 0; i < 4; i++) {
			nexR = curR + dr[dir][i];
			nexC = curC + dc[dir][i];
			
			if (graph[nexR][nexC] == 0) {
				isPushed = true;
				 nexdir = (dir - 1 - i);
				if (nexdir < 0) nexdir += 4;
				q.push({ nexR ,nexC, nexdir });
				break;
			}
		}

		if (isPushed) continue;
		//뒤로가야하는데 막혔으면 break;
		switch (dir) {
			case 0:
				nexR = curR + 1;
				nexC = curC;
				break;
			case 1:
				nexR = curR;
				nexC = curC - 1;
				break;
			case 2:
				nexR = curR - 1;
				nexC = curC;
				break;
			case 3:
				nexR = curR;
				nexC = curC + 1;
				break;
			default:
				break;
		}

		if (graph[nexR][nexC] == 1) {
			break;
		}
		else {
			q.push({ nexR ,nexC, dir });
		}
	}

	cout << answer;
}