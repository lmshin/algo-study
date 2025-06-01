#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void rotate_clockwise(deque<int>& gear) {
	
	int last = gear.back();
	gear.pop_back();
	gear.push_front(last);
	
	return;
}

void rotate_counter_clockwise(deque<int>& gear) {

	int front = gear.front();
	gear.pop_front();
	gear.push_back(front);

	return;
}

int main() {
	vector<deque<int>> gear(4, deque<int>(8, 0));
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = s[j] - '0';
		}
	}

	int n, target_gear, direction;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target_gear >> direction;
		
		int dir[4] = {0};
		target_gear--;
		dir[target_gear] = direction;

		//왼쪽으로 전파
		for (int j = target_gear - 1; j >= 0; j--) {
			if (gear[j][2] != gear[j + 1][6]) {
				dir[j] = -dir[j + 1];
			}
			else break;
		}

		//오른쪽으로 전파
		for (int j = target_gear + 1; j < 4; j++) {
			if (gear[j][6] != gear[j - 1][2]) {
				dir[j] = -dir[j - 1];
			}
			else break;
		}

		//회전
		for (int j = 0; j < 4; j++) {
			if (dir[j] == 1) {
				rotate_clockwise(gear[j]);
			}
			else if (dir[j] == -1) {
				rotate_counter_clockwise(gear[j]);
			}
		}

	}

	int sum = 0;
	for (int j = 0; j < 4; j++) {
		if (gear[j][0] == 1) {
			sum += (1 << j);
		}
	}
	cout << sum;
	return 0;
}