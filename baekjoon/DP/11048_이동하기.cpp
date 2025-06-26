#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (i == 1 || j == 1) dp[i][j] = map[i][j];
		}
	}

	int sum = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][1] += dp[i - 1][1];
	}

	for (int i = 2; i <= m; i++) {
		dp[1][i] += dp[1][i - 1];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = max(map[i][j] + dp[i - 1][j - 1], map[i][j] + dp[i - 1][j], map[i][j] + dp[i][j-1]);
		}
	}

	cout << dp[n][m] << endl;

}