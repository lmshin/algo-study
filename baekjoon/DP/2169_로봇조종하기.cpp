#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
int graph[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
}

int make_dp() {
	//ù��° �� �ʱ�ȭ
	vector<int> left(m + 1, 0);
	vector<int> right(m + 1, 0);

	for (int i = 1; i <= m; i++) {
		dp[1][i] = graph[1][i] + dp[1][i - 1];
	}

	//�ι�° ����ʹ� �ٸ��� �����ؾ� �ϴµ�
	//�ϴ� ������ ������ vector �ϳ� ����
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = graph[i][j] + dp[i-1][j];
		}
		
		//���ʿ��� ���� ���� ���� �����鼭 �ִ밪�� ������
		left[1] = dp[i][1];
		for (int j = 2; j <= m; j++) {
			left[j] = max(left[j - 1] + graph[i][j], dp[i][j]);
		}
		//�����ʿ��� ���� ���� ���� �����鼭 �ִ밪�� �ֽ�ȭ
		right[m] = dp[i][m];
		for (int j = m-1; j >= 1; j--) {
			right[j] = max(right[j + 1] + graph[i][j], dp[i][j]);
		}
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(left[j], right[j]);
		}
	}

	return dp[n][m];

}

int main() {
	input();
	cout << make_dp();

}