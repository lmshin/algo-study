#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool search(unsigned int target, vector<unsigned int>& arr) {
	int start = 0;
	int end = arr.size() - 1;
	int pivot;

	while (start <= end) {
		pivot = (start + end) / 2;

		if (target < arr[pivot]) {
			end = pivot - 1;
		}
		else if (target > arr[pivot]) {
			start = pivot + 1;
					}
		else if(target == arr[pivot]) {
			return true;
		}
	}

	return false;
}

int main() {
	int a, b;
	cin >> a >> b;
	vector<unsigned int> A(a);
	for (int i = 0; i < a; i++) {
		cin >> A[i];
	}

	vector<unsigned int> B(b);
	for (int i = 0; i < b; i++) {
		cin >> B[i];
	}
	sort(B.begin(), B.end());

	vector<unsigned int> answer;
	for (int i = 0; i < A.size(); i++) {
		if (!search(A[i], B)) {
			answer.push_back(A[i]);
		}
	}

	if (!answer.empty()) {
		cout << answer.size() << "\n";
		for (unsigned int num : answer) {
			cout << num << " ";
		}
	}
	else {
		cout << "0";
	}
}