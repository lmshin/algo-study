#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "0" << "\n";
		return 0;
	}

	int input;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> input;
		pq.push(input);
	}

	int sum = 0, answer = 0;
	int count = 0;
	while (!pq.empty()) {

		if (count < 2) {
			count++;
			sum += pq.top();
			pq.pop();
			if (pq.empty()) {
				answer += sum;
				break;
			}
		}
		else {
			answer += sum;
			pq.push(sum);
			count = 0;
			sum = 0;
		}
	}

	cout << answer;

	return 0;
}