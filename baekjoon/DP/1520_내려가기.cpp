#include<iostream>
#include<vector>
using namespace std;
int map[501][501];
int dp[501][501];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;

int dfs(int x, int y) {
	if (x + 1 == m && y + 1 == n) {
		return 1;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	
	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (map[ny][nx] < map[y][x]) {
			dp[y][x] += dfs(nx, ny);
		}
	}

	return dp[y][x];
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}	

	cout << dfs(0, 0);

	return 0;
}