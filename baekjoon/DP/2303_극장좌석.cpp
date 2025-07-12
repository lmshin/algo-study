#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> length_buffer;
	int cnt = 0;
	int n, m, input;
	int before_idx = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		length_buffer.push_back(input - before_idx - 1);
		before_idx = input;
	}
	length_buffer.push_back(n - before_idx);

	//dp구해놓기
	int dp[41] = { 0 };
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	unsigned int answer = 1;
	for (int i = 0; i < length_buffer.size(); i++) {
		if (length_buffer[i] != 0) {
			answer *= dp[length_buffer[i]];
		}
	}

	cout << answer;
}