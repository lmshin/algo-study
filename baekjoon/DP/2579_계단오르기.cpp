#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define MAX 300
int dp[MAX + 1] = { 0 };

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	//어떻게 찾을까?
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = max(v[1] + v[3], v[2] + v[3]);
	dp[4] = max(dp[1] + v[3] + v[4], dp[2] + v[4]);

	for (int i = 5; i <= n; i++) {
		int cost = v[i];
		dp[i] = max(dp[i - 3] + v[i - 1] + cost, dp[i - 2] + cost); 
	}

	cout << dp[n] << "\n";
}