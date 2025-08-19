#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int graph[101][101];
int n, l;

void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
}

bool check_col(int col) {
	int level_changed = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n - 1; i++) {
		int level_diff = abs(graph[i][col] - graph[i + 1][col]);
		//차이가 1인 경우 level_changed ++
		if (level_diff == 1) {
			level_changed++;
		}
		//차이가 2이상인 경우 false return 
		else if (level_diff >= 2) {
			return false;
		}
	}

	if (level_changed == 0) return true;

	int left_count = 1;
	int can_go_left = 0;
	int right_count = 1;
	int can_go_right = 0;
	for (int i = 0; i < n - 1; i++) {
		//레벨이 높아진다면 경사로를 놓을 수 있는지 확인
		//조건 : 이전의 연속된 레벨이 L 이상인가?

		//위에서 내려가는 경우
		//같으면 left_count++
		if (graph[i][col] == graph[i + 1][col]) {
			left_count++;
		}
		//올라가는 경우, 이전의 count가 l 보다 긴지 확인
		//짧다면 불가능 한거니까 바로 return false
		else if (graph[i][col] < graph[i + 1][col]) {
			if (left_count >= l) {
				can_go_left++;
				for (int j = i; j > i - l; j--) {
					if (visited[j]) return false;
					else visited[j] = true;
				}

			}
			else {
				return false;
			}

			left_count = 1;
		}
		//내려가는 경우
		else {
			left_count = 1;
		}

		//아래에서 올라가는 경우
		if (graph[n - i - 1][col] == graph[n - i - 2][col]) {
			right_count++;
		}
		else if (graph[n - i - 1][col] < graph[n - i - 2][col]) {
			if (right_count >= l) {
				can_go_right++;
				for (int j = n - i - 1; j < n - i - 1 + l; j++) {
					if (visited[j]) return false;
					else visited[j] = true;
				}
			}
			else {
				return false;
			}

			right_count = 1;
		}
		else {
			right_count = 1;
		}

	}

	if (can_go_left + can_go_right == level_changed) {
		return true;
	}
	else {
		return false;
	}
}

bool check_row(int row) {
	int level_changed = 0;

	for (int i = 0; i < n-1; i++) {
		int level_diff = abs(graph[row][i] - graph[row][i + 1]);
		//차이가 1인 경우 level_changed ++
		if (level_diff == 1) {
			level_changed++;
		}
		//차이가 2이상인 경우 false return 
		else if (level_diff >= 2) {
			return false;
		}
	}
	
	if (level_changed == 0) return true;

	//왼쪽 확인
	int left_count = 1;
	int can_go_left = 0;
	int right_count = 1;
	int can_go_right = 0;
	vector<bool> visited(n, 0);

	for (int i = 0; i < n - 1; i++) {
		//레벨이 높아진다면 경사로를 놓을 수 있는지 확인
		//조건 : 이전의 연속된 레벨이 L 이상인가?

		//왼쪽에서 가는 경우
		if (graph[row][i] == graph[row][i+1]) {
			left_count++;
		}
		else if (graph[row][i] < graph[row][i + 1]) {
			if (left_count >= l) {
				can_go_left++;
				//좌표를 저장한다.
				//i 부터 i - l 까지 저장
				for (int j = i; j > i - l; j--) {
					if (visited[j]) return false;
					else visited[j] = true;
				}
			}
			else {
				return false;
			}

			left_count =1;
		}
		else {
			left_count = 1;
		}

		//오른쪽에서 가는 경우
		if (graph[row][n - i - 1] == graph[row][n -i - 2]) {
			right_count++;
		}
		else if (graph[row][n - i - 1] < graph[row][n - i - 2]) {
			if (right_count >= l) {
				can_go_right++;
				for (int j = n - i - 1; j < n - i - 1 + l; j++) {
					if (visited[j]) return false;
					else visited[j] = true;
				}
			}
			else {
				return false;
			}

			right_count = 1;
		}
		else {
			right_count = 1;
		}

	}

	if (can_go_left + can_go_right == level_changed) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	
	cin >> n >> l;

	input();

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (check_row(i)) {
			//cout << "row : " << i << "\n";
			answer++;
		} 
		if (check_col(i)) {
			//cout << "col : " << i << "\n";
			answer++;
		} 
	}

	cout << answer;
}