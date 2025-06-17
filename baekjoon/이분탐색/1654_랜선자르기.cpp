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
		
		if (isPossible(v, length, k, answer)) { //가능하다? -> 길이 더 늘려보자, 그리고 이때의 값을 answer 에 저장
			start = mid + 1;
		}
		else {// 불가능하다? -> 길이를 더 짧게!
			end = mid - 1;
		}
	}

	cout << answer;
	return 0;
}