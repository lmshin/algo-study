#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<unsigned short>> max_dp(2, vector<unsigned short>(3, 0));
	vector<vector<unsigned short>> min_dp(2, vector<unsigned short>(3, 0));


	int col[3];
	cin >> col[0] >> col[1] >> col[2];
	
	for (int i = 0; i < 3; i++) {
		max_dp[0][i] = col[i];
		min_dp[0][i] = col[i];
	}


	for (int i = 1; i < n; i++) {
		cin >> col[0] >> col[1] >> col[2];

		max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + col[0];
		max_dp[1][1] = max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2])) + col[1];
		max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + col[2];

		min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + col[0];
		min_dp[1][1] = min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2])) + col[1];
		min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + col[2];

		for (int i = 0; i < 3; i++) {
			max_dp[0][i] = max_dp[1][i];
			min_dp[0][i] = min_dp[1][i];
		}
	}

	int max_answer = max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2]));
	int min_answer = min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2]));
	
	cout << max_answer << " " << min_answer << endl;
}