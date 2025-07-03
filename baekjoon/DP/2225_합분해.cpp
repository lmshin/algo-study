#include<iostream>
#include<vector>
using namespace std;

//int dp[201][202] = { 0 };
int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<long long>> dp(k, vector<long long>(n+2, 0));

	if (k == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (k == 2) {
		cout << n + 1 << endl;
		return 0;
	}
	
	for (int i = 1; i <= n+1; i++) {
		dp[1][i] = 1;
	}

 	long long MOD = 1000000000;
	for (int i = 2; i < k; i++) {
		for (int j = 1; j <= n+1; j++) {
			for (int k = 1; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}

	long long answer = 0;
	for (int i = 1; i <= n+1; i++) {
		answer = (answer + dp[k - 1][i]) % MOD; 
		answer %= MOD;
	}
	
	cout << answer << endl;
}