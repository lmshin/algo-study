#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(int start, const vector<int>& map, int& answer, int distance1, int distance2, int count) {
	count++;

	if (count == 1) {//ù��° ����
		for (int i = start + 1; i < map.size(); i++) {
			int first_jump = map[i] - map[start];
			dfs(i, map, answer, first_jump, distance2, count);
		}
	}
	else if (count == 2) {//�ι�° ����
		for (int i = start + 1; i < map.size(); i++) {
			int second_jump = map[i] - map[start];
			dfs(i, map, answer, distance1, second_jump, count);
		}
	}
	else if (count == 3) {
		if (distance1 <= distance2 && distance2 <= (distance1 * 2)) {
			answer++;
		}
	}

	return;
}

int main() {
	int n, pos;
	int answer = 0;
	cin >> n;
	vector<int> map;

	for (int i = 0; i < n; i++) {
		cin >> pos;
		map.push_back(pos);
	}

	sort(map.begin(), map.end());

	int count,current_pos, first_jump, second_jump;
	for (int i = 0; i < n; i++) {
		count = 0;//���⼭ ���� �ʱ�ȭ
		first_jump = 0;
		second_jump = 0;
		dfs(i, map, answer, first_jump, second_jump, 0);
	}

	cout << answer << endl;

	return 0;
}