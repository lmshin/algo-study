#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> candidates;
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	candidates.resize(n + 1);
	dp.resize(n + 2, 0);

	int time, val;
	for (int i = 1; i <= n; i++) {
		cin >> time >> val;
		candidates[i].first = time;
		candidates[i].second = val;
	}

	int answer = 0;

	//뒤에서 부터 dp테이블 채우기
	for (int i = n; i >= 1; i--) {

		time = candidates[i].first;
		val = candidates[i].second;

		if (i + time - 1 > n) {
			dp[i] = answer;
			continue;
		}
		dp[i] = max(dp[i + time] + val, answer);
		answer = max(answer, dp[i]);
	}

	cout << answer;
}