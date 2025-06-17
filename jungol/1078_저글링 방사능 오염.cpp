#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int row, col;

int max(int a, int b) {
	return a > b ? a : b;
}

void bfs(vector<vector<int>>& map, vector<vector<bool>>& check, int start_x, int start_y) {
	map[start_y][start_x] += 2;
	check[start_y][start_x] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));

	int nx, ny, cx, cy;
	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (1 <= nx && nx <= col && 1 <= ny && ny <= row && !check[ny][nx] && map[ny][nx] == 1) {
				map[ny][nx] = map[cy][cx] + 1;
				check[ny][nx] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

int main() {
	
	cin >> col >> row;
	vector<vector<int>> map(row + 1, vector<int>(col + 1, 0));
	vector<vector<bool>> check(row + 1, vector<bool>(col + 1, false));
	//입력
	string s;
	for (int i = 1; i <= row; i++) {
		cin >> s;
		for (int j = 1; j <= col; j++) {
			map[i][j] = s[j-1] - '0';
		}
	}
	int start_x, start_y;
	cin >> start_x >> start_y;
	//계산
	bfs(map, check, start_x, start_y);

	//출력
	int alived = 0;
	int last_deaded = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			last_deaded = max(map[i][j], last_deaded);
			if (map[i][j] == 1) alived++;
		}
	}


	/*for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}*/

	cout << last_deaded << "\n";
	cout << alived << "\n";

	return 0;
}