#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n, k;

vector<int> prefix_sum;
map<int, int> prefix_k;

int main() {
	cin >> n >> k;
	//입력받으면서 절대값이 k로 나눠 떨어지면 따로 저장
	int num;

	prefix_sum.resize(n + 1, 0);
	prefix_k[0] = 1;
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		prefix_sum[i] = prefix_sum[i-1] + num;
		answer += prefix_k[prefix_sum[i] - k];
		prefix_k[prefix_sum[i]] += 1;
	}

	cout << answer;
}