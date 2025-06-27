#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max(int a, int b, int c) {
	if (a > b) {
		if (b > c) {
			return a + b;
		}
		else {
			return a + c;
		}
	}
	else {//b가 같거나 더 큰 경우
		if (a > c) {
			return a + b;
		}
		else {
			return b + c;
		}
	}

	
}


int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1,0);
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	
	if (n == 1) {
		cout << v[n] << endl;
		return 0;
	}
	else if (n == 2) {
		cout << v[n] + v[n - 1] << endl;
		return 0;
	}
	else if (n == 3) {
		cout << max(v[n], v[n - 1], v[n - 2]) << endl;
		return 0;
	}
	else {
		dp[n] = v[n];
		dp[n - 1] = v[n] + v[n - 1];
		dp[n - 2] = max(v[n], v[n - 1], v[n - 2]);
	}

	int Max = dp[n - 2];
	for (int i = n-3; i >= 1; i--) {
		dp[i] = max(max(v[i] + v[i + 1] + dp[i + 3], v[i] + dp[i + 2]), Max);
		Max = max(Max, dp[i]);
	}

	cout << dp[1] << endl;
}