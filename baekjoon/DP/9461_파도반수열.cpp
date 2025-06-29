#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>problem(n);

	for (int i = 0; i < n; i++) {
		cin >> problem[i];
	}
	int Max = *max_element(problem.begin(), problem.end());
	vector<long long> dp(Max + 1, 0);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 5; i < Max; i++) {
		dp[i + 1] = dp[i] + dp[i - 4];
	}

	for (int i = 0; i < problem.size(); i++) {
		cout << dp[problem[i]] << endl;
	}

	return 0;
}