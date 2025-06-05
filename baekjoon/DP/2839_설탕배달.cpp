#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	//3, 5 �� ���� �� �ִ� �ּ����� ������ ���� ���ϴ� ����,
	vector<int> dp(5001, 0); //�ñ��ؼ� ã�ƺ�, int * 5000 �� vector�� �Ҵ��ϸ� �󸶸�ŭ�� �޸𸮸� ��ƸԴ°�?
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = -1;
	dp[8] = 2;
	dp[9] = 3;
	dp[10] = 2;
	dp[11] = 3;
	dp[12] = 4; //���⼭ ���� ��ȭ���� ����ȴ�.
	for (int i = 13; i <= n; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	cout << dp[n] << '\n';

	return 0;
}