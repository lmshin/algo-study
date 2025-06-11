#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int n;
	bool flag = true;
	cin >> n;

	stack<int> s;
	vector<int> v(n);
	vector<char> answer;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int number_idx = 1;
	int target_idx = 0;

	//처음 숫자까지 넣고 시작
	while (number_idx <= v[target_idx]) {
		s.push(number_idx);
		answer.push_back('+');
		number_idx++;
	}

	while (target_idx < n) {

		if (s.size() == 0) {
			s.push(number_idx);
			answer.push_back('+');
			number_idx++;

			while (s.top() < v[target_idx]) {
				s.push(number_idx);
				answer.push_back('+');
				number_idx++;
			}
		}
		else if (s.top() == v[target_idx]) { //s.top값이 target_idx 랑 일치한다면? ex) 5 4 3
			s.pop();
			answer.push_back('-');
			target_idx++;
		}
		else if (s.top() > v[target_idx]) {//조건이 하나 더 있어야 할듯 , s.top값이 target_idx 보다 작다면? ex) 5 3 1
			cout << "NO" << '\n';
			flag = false;
			break;
		}
		else if (s.top() < v[target_idx]) { //5 8 4
			while (s.top() < v[target_idx]) {
				s.push(number_idx);
				answer.push_back('+');
				number_idx++;
			}
		}
	}
	if (flag) {
		for (char ch : answer) {
			cout << ch << '\n';
		}
	}
	return 0;
}