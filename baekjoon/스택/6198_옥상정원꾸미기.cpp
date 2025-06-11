#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<pair<int,int>> s;
	int height;
	unsigned int answer = 0;


	//����ְ� ����
	cin >> height;
	s.push(make_pair(1, height));

	for (int i = 1; i < n; i++) {
		cin >> height;
		
		if (s.top().second > height) { //������ ���� �ǹ��� ���̰� ���� ��� push
			s.push(make_pair(i + 1, height));
		}
		else {//������ ���� �ǹ��� ���̰� ���� ��� idx ����ϸ鼭 pop, idx ���
			while (!s.empty() && s.top().second <= height) {
				int idx = (i + 1) - s.top().first - 1;
				answer += idx;
				s.pop();
			}
			s.push(make_pair(i + 1, height));
		}
	}

	//�����ִ� stack �� ���ؼ� ó���Ѵ�
	//12 7 6 5 ������ �� �ۿ� ����
	int first_idx = s.top().first;
	while (!s.empty()) {
		int idx = s.top().first;
		s.pop();
		answer += first_idx - idx;
	}

	cout << answer << "\n";

	return 0;
}