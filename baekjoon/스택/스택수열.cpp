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

	//ó�� ���ڱ��� �ְ� ����
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
		else if (s.top() == v[target_idx]) { //s.top���� target_idx �� ��ġ�Ѵٸ�? ex) 5 4 3
			s.pop();
			answer.push_back('-');
			target_idx++;
		}
		else if (s.top() > v[target_idx]) {//������ �ϳ� �� �־�� �ҵ� , s.top���� target_idx ���� �۴ٸ�? ex) 5 3 1
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