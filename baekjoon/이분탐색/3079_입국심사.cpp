#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int n, m, t;
long long answer = LLONG_MAX;;
vector<long long> times;

bool check(long long time) {
	//주어진 time 을 각 심사대로 나눈 몫들
	//4.5 들이 있다면? 20명 이라면?, 최대 100초
	long long sum = 0;
	//50초로 확인
	for (int i = 0; i < n; i++) {
		sum += time / times[i];
		if (sum >= m) return true;
	}

	return false;
}

int main() {
	cin >> n >> m;
	times.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}

	//심사를 받는데 걸리는 최소값을 이분탐색으로 정하고 확인한다.
	long long start, end, mid;
	start = 1;
	end = *max_element(times.begin(), times.end()) * m;

	while (start <= end) {
		mid = (start + end) / 2;

		if (check(mid)) { //가능하면 더 줄여본다.
			end = mid - 1;
			answer = mid;
		}
		else {
			start = mid + 1;
		}

	}

	cout << answer;
}