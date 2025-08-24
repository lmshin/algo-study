#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
int graph[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
}

int make_dp() {
	//첫번째 행 초기화
	vector<int> left(m + 1, 0);
	vector<int> right(m + 1, 0);

	for (int i = 1; i <= m; i++) {
		dp[1][i] = graph[1][i] + dp[1][i - 1];
	}

	//두번째 행부터는 다르게 접근해야 하는데
	//일단 위에서 내려온 vector 하나 만듬
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = graph[i][j] + dp[i-1][j];
		}
		
		//왼쪽에서 부터 값을 더해 나가면서 최대값을 저장함
		left[1] = dp[i][1];
		for (int j = 2; j <= m; j++) {
			left[j] = max(left[j - 1] + graph[i][j], dp[i][j]);
		}
		//오른쪽에서 부터 값을 더해 나가면서 최대값을 최신화
		right[m] = dp[i][m];
		for (int j = m-1; j >= 1; j--) {
			right[j] = max(right[j + 1] + graph[i][j], dp[i][j]);
		}
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(left[j], right[j]);
		}
	}

	return dp[n][m];

}

int main() {
	input();
	cout << make_dp();

}