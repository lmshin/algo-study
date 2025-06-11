#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void left_rotation(deque<int>& d) {
	int tmp = d.front();
	d.pop_front();
	d.push_back(tmp);

	return;
}

void right_rotation(deque<int>& d) {
	int tmp = d.back();
	d.pop_back();
	d.push_front(tmp);

	return;
}

int find_target_index(deque<int>& d, int target) {
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == target) return i;
	}

	return -1;
}

int main() {
	int n,m;
	cin >> n >> m;
	deque<int> d(n);
	//deque에 1 ~ n 까지 채워넣기
	for (int i = 1; i <= n; i++) {
		d[i - 1] = i;
	}

	//target을 입력받는다!
	int target, left, right, target_idx;
	int answer = 0;
	for (int i = 0; i < m; i++) {
		cin >> target;

		//target의 queue 에서의 idx를 찾는다.
		target_idx = find_target_index(d, target);
		//queue의 위치에서 왼쪽이 가까운지 오른쪽이 가까운지 확인
		left = target_idx;
		right = d.size() - target_idx;
		

		if (left < right) {
			for (int j = 0; j < left; j++) {
				answer++;
				left_rotation(d);
			}
			d.pop_front();
		}
		else {
			for (int j = 0; j < right; j++) {
				answer++;
				right_rotation(d);
			}
			d.pop_front();
		}

	}

	cout << answer << "\n";

	return 0; 
}