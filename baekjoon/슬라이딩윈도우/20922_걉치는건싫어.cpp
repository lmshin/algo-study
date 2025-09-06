#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
int n, k;

vector<int> numbers;
unordered_map<int, int> num_count;

int main() {
	cin >> n >> k;
	int start = 0;
	int answer = 0;

	numbers.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < n; i++) {
		num_count[numbers[i]]++;

		while (num_count[numbers[i]] > k) {
			num_count[numbers[start++]]--;
		}

		answer = max(answer, i - start + 1);
	}

	cout << answer;
}