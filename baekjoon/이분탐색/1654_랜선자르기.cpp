#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

bool isPossible(vector<unsigned int>& v, unsigned int length, int k , unsigned int& answer) {
	
	unsigned int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / length;
	}

	if (cnt >= k) {
		answer = max(answer, length);
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int k, n;
	cin >> n >> k;
	vector<unsigned int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	unsigned int start = 1;
	unsigned int end = v[v.size() - 1];
	unsigned int mid, length, answer = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		length = mid;
		
		if (isPossible(v, length, k, answer)) { //�����ϴ�? -> ���� �� �÷�����, �׸��� �̶��� ���� answer �� ����
			start = mid + 1;
		}
		else {// �Ұ����ϴ�? -> ���̸� �� ª��!
			end = mid - 1;
		}
	}

	cout << answer;
	return 0;
}