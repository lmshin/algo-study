#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 52
char map[MAX][MAX];
bool visited[MAX][MAX] = { 0 };
using namespace std;
int row, col, cx, cy, nx, ny;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void input() {
	for (int i = 0; i < row + 2; i++) {
		for (int j = 0; j < col + 2; j++) {
			if (i == 0 || i == row + 1 || j == 0 || j == col + 1) {
				map[i][j] = 'W';
			}
			else {
				cin >> map[i][j];
			}
		}
	}
}

int bfs(int x, int y) {
	//방문한적없는 육지인 경우 실행된다.
	int Max = 0;
	int tmp_map[MAX][MAX] = { 0 };
	bool visited[MAX][MAX] = { 0 };

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visited[y][x] = true;
	tmp_map[y][x] = 0;

	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (map[ny][nx] == 'L' && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push(make_pair(nx, ny));
				tmp_map[ny][nx] = tmp_map[cy][cx] + 1;
				Max = max(Max, tmp_map[ny][nx]);
			}
		}
	}

	return Max;
}

//int find() {
//	int max = -1;
//	for (int i = 1; i < row + 1; i++) {
//		for (int j = 1; j < col + 1; j++) {
//			if (max < tmp_map[i][j]) max = tmp_map[i][j];
//		}
//	}
//
//	return max;
//}

int main() {
	cin >> row >> col;
	input();
	
	vector<int> results;
	for (int i = 1; i < row + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			if (map[i][j] == 'L') {
				results.push_back(bfs(j, i));
			}
		}
	}

	int answer = *max_element(results.begin(), results.end());
	//int answer = find();
	cout << answer << endl;

	return 0;
}