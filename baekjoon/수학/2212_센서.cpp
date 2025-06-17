#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> sensors(n);
	vector<int> gap(n-1);
	for (int i = 0; i < n; i++) {
		cin >> sensors[i];
	}

	sort(sensors.begin(), sensors.end());

	for (int i = 0; i < n-1; i++) {
		gap[i] = sensors[i + 1] - sensors[i];
	}

	sort(gap.begin(), gap.end());

	int answer = 0;
	for (int i = 0; i < n - k; i++) {
		answer += gap[i];
	}

	cout << answer;
	return 0;
}