#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(int start, const vector<int>& stones, int& answer, int distance1, int distance2, int count) {
	count++;

	if (count == 1) {//첫번째 도약
		for (int i = start + 1; i < stones.size(); i++) {
			int first_jump = stones[i] - stones[start];
			dfs(i, stones, answer, first_jump, distance2, count);
		}
	}
	else if (count == 2) {//두번째 도약
		for (int i = start + 1; i < stones.size(); i++) {
			int second_jump = stones[i] - stones[start];
			dfs(i, stones, answer, distance1, second_jump, count);
		}
	}
	else if (count == 3) {
		if (distance1 <= distance2 && distance2 <= (distance1 * 2)) {
			answer++;
		}
		
		return;
	}
}

int main() {
	int n, pos;
	int answer = 0;
	cin >> n;
	vector<int> stones;

	for (int i = 0; i < n; i++) {
		cin >> pos;
		stones.push_back(pos);
	}

	sort(stones.begin(), stones.end());

	int count,current_pos, first_jump, second_jump;
	for (int i = 0; i < n; i++) {
		count = 0;//여기서 변수 초기화
		first_jump = 0;
		second_jump = 0;
		dfs(i, stones, answer, first_jump, second_jump, 0);
	}

	cout << answer << endl;

	return 0;
}