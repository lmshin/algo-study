#include<iostream>
#include<vector>

using namespace std;

//가장 긴 증가하는 수열 문제랑 비슷한듯
int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 1001);
	for (int i = 1; i < n + 1; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	int j = 0;

	dp[n] = 0;
	for (int i = n; i >= 1; i--) {
		cnt = v[i];
		j = i;
		while(cnt--&&j++) {
			if (j > n) {
				break;
			}
			dp[i] = min(dp[i], dp[j] + 1);
		}
	}

	if (dp[1] >= 1001) {
		cout << "-1" << endl;
	}
	else {
		cout << dp[1] << endl;
	}
	
	
	return 0;
}