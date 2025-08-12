#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	deque<int> answer;
	int tmp = n + 1 - (a + b);

	if (tmp < 0) {
		cout << "-1";
		return 0; 
	}


	if (a >= b) {
		for (int i = 1; i <= a; i++) {
			answer.push_back(i);
		}
		for (int i = b - 1; i >= 1; i--) {
			answer.push_back(i);
		}
		for (int i = 0; i < tmp; i++) {
			answer.push_front(1);
		}
	}
	else {
		for (int i = b; i >= 1; i--) {
			answer.push_back(i);
		}
		for (int i = a-1; i >= 1; i--) {
			answer.push_front(i);
		}
		//맨 앞 바로 뒤에 넣어 주어야 한다.
		int temp = answer.front();
		answer.pop_front();
		for (int i = 0; i < tmp; i++) {
			answer.push_front(1);
		}
		answer.push_front(temp);
	}

	
	

	for (int i = 0; i < n; i++) {
		cout << answer.front() << " ";
		answer.pop_front();
	}
}