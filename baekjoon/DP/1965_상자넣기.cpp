#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> map(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	vector<int> dp(n, 1);
	dp[n - 1] = 1;
	int answer = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (map[i] < map[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}