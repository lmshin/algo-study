#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	//3, 5 로 만들 수 있는 최소한의 봉지의 수를 구하는 문제,
	vector<int> dp(5001, 0); //궁금해서 찾아봄, int * 5000 을 vector로 할당하면 얼마만큼의 메모리를 잡아먹는가?
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = -1;
	dp[8] = 2;
	dp[9] = 3;
	dp[10] = 2;
	dp[11] = 3;
	dp[12] = 4; //여기서 부터 점화식이 적용된다.
	for (int i = 13; i <= n; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	cout << dp[n] << '\n';

	return 0;
}