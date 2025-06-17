#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//계산
	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size() - 1;
	pair<int, int> answer = { 0,0 };
	long long min_result = LLONG_MAX;
	long long result;

	while (start < end) {
		result = v[start] + v[end];
		
		if (abs(min_result) > abs(result)) {
			min_result = result;
			answer.first = v[start];
			answer.second = v[end];
		}
		
		if (result > 0) {
			end--;
		}
		else if (result < 0) {
			start++;
		}
		else {
			break;
		}
	}

	//출력
	cout << answer.first << " " << answer.second;
	
}