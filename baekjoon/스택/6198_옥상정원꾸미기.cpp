#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<pair<int,int>> s;
	int height;
	unsigned int answer = 0;


	//집어넣고 시작
	cin >> height;
	s.push(make_pair(1, height));

	for (int i = 1; i < n; i++) {
		cin >> height;
		
		if (s.top().second > height) { //다음에 오는 건물의 높이가 낮은 경우 push
			s.push(make_pair(i + 1, height));
		}
		else {//다음에 오는 건물의 높이가 높은 경우 idx 계산하면서 pop, idx 계산
			while (!s.empty() && s.top().second <= height) {
				int idx = (i + 1) - s.top().first - 1;
				answer += idx;
				s.pop();
			}
			s.push(make_pair(i + 1, height));
		}
	}

	//남아있는 stack 에 대해서 처리한다
	//12 7 6 5 형태일 수 밖에 없음
	int first_idx = s.top().first;
	while (!s.empty()) {
		int idx = s.top().first;
		s.pop();
		answer += first_idx - idx;
	}

	cout << answer << "\n";

	return 0;
}