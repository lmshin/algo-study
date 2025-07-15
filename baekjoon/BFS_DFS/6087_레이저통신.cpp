#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int d[4] = { 1,2,3,4 };

typedef struct Pos{
	int x;
	int y;
	int dir;
	int rotations;
}Pos;

int main() {
	int w, h;
	char map[102][102] = { 0 };
	

	string input;
	vector<pair<int, int>> pos;

	cin >> w >> h;

	for (int i = 1; i <= h; i++) {
		cin >> input;
		for (int j = 1; j <= w; j++) {
			map[i][j] = input[j - 1];
			if (map[i][j] == 'C') {
				pos.push_back(make_pair(j, i));
			}
		}
	}

	int costMap[102][102][5] = {0};
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			for (int k = 1; k < 5; k++) {
				if (map[i][j] == 'C' || map[i][j] == '.') {
					costMap[i][j][k] = 0x7fffffff;
				}
			}
		}
	}

	queue<Pos> q;
	for (int k = 1; k < 5; k++) {
		costMap[pos[0].second][pos[0].first][k] = 0;
	}
	
	q.push({ pos[0].first, pos[0].second,0,0 });

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curD = q.front().dir;
		int curR = q.front().rotations;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			int nextD = d[i];
			int nextR = curR;

			if (map[nextY][nextX] == '.' || map[nextY][nextX] == 'C') {
				if (curD != 0 && curD != nextD) {
					nextR = curR + 1;
				}

				if (costMap[nextY][nextX][nextD] > nextR) {
					costMap[nextY][nextX][nextD] = nextR;
					q.push({ nextX, nextY, nextD, nextR });
				}
				
			}
		}
		
	}

	int answer = 0x7fffffff;
	for (int k = 1; k < 5; k++) {
		answer = min(answer, costMap[pos[1].second][pos[1].first][k]);
	}
	cout << answer;
	
}