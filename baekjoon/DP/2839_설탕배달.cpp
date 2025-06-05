#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	//3, 5 �� ���� �� �ִ� �ּ����� ������ ���� ���ϴ� ����,
	vector<int> dp(n + 1, 0); //�ñ��ؼ� ã�ƺ�, int * 5000 �� vector�� �Ҵ��ϸ� �󸶸�ŭ�� �޸𸮸� ��Ƹ���? 20KB, ���������� 128MB, �ð����� 1��
	dp[3] = 1;				 //�����Ҵ����� �ϸ� �޸𸮸� �� �� ���Ծ���, push_back���� ����ϸ� �׶����� �ǵڿ� �޸𸮸� �Ҵ��Ѵ�, �޸𸮴� ���Ծ������� ���귮�� �ξ� ��������.
	dp[4] = -1;				 //push_back�� ���귮�� capacitor �� ���� �������� �迭 ��ü�� �Űܾ� �ϱ� ������ ���귮�� �ξ� ��������.
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
	checkCapacityOfVector();

	return 0;
}

void checkCapacityOfVector() {
	std::vector<int> v;
	for (int i = 0; i < 1000; ++i) {
		v.push_back(i);
		std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << "\n";
	}
}