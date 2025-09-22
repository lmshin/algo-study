#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int k, w, h;
int graph[201][201];
int visit[201][201][31];

// 원숭이 이동
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 말 이동
int hx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int hy[8] = { -2,-1,1,2,2,1,-1,-2 };

struct Node {
	int x;
	int y;
	int useHorse;
};

void input() {
	cin >> k;
	cin >> w >> h; 
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> graph[i][j];
		}
	}
}

int bfs() {
	queue<Node> q;
	q.push({ 1,1,0 });
	visit[1][1][0] = 1;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curUse = q.front().useHorse;
		int curDist = visit[curY][curX][curUse];
		q.pop();

		if (curX == w && curY == h) {
			return curDist - 1;
		}
		

		//원숭이 이동
		for (int i = 0; i < 4; i++) {
			int nexX = curX + dx[i];
			int nexY = curY + dy[i];

			if (nexX < 1 || nexX > w || nexY < 1 || nexY > h) continue;
			if (graph[nexY][nexX] == 1) continue;
			if (visit[nexY][nexX][curUse]) continue;

			visit[nexY][nexX][curUse] = curDist + 1;
			q.push({ nexX,nexY,curUse });

		}

		//말이동
		if (curUse < k) {
			for (int i = 0; i < 8; i++) {
				int nexX = curX + hx[i];
				int nexY = curY + hy[i];

				if (nexX < 1 || nexX > w || nexY < 1 || nexY > h) continue;
				if (graph[nexY][nexX] == 1) continue;
				if (visit[nexY][nexX][curUse + 1]) continue;

				visit[nexY][nexX][curUse + 1] = curDist + 1;
				q.push({ nexX,nexY,curUse + 1 });

			}
		}
		
	}

	return -1;
}

int main() {
	input();
	cout << bfs();
}