#include<queue>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t, n, input;
	cin >> t;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> input;
			pq.push(input);
		}

		int count = 0;
		long long sum = 0, answer = 0;

		while (!pq.empty()) {

			sum += pq.top();
			pq.pop();

			if (pq.empty()) {
				answer += sum;
				break;
			}

			count++;

			if (count == 2) {
				answer += sum;
				pq.push(sum);
				count = 0;
				sum = 0;
			}

		}

		cout << answer << "\n";
	}
}