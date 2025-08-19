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
		//���̰� 1�� ��� level_changed ++
		if (level_diff == 1) {
			level_changed++;
		}
		//���̰� 2�̻��� ��� false return 
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
		//������ �������ٸ� ���θ� ���� �� �ִ��� Ȯ��
		//���� : ������ ���ӵ� ������ L �̻��ΰ�?

		//������ �������� ���
		//������ left_count++
		if (graph[i][col] == graph[i + 1][col]) {
			left_count++;
		}
		//�ö󰡴� ���, ������ count�� l ���� ���� Ȯ��
		//ª�ٸ� �Ұ��� �ѰŴϱ� �ٷ� return false
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
		//�������� ���
		else {
			left_count = 1;
		}

		//�Ʒ����� �ö󰡴� ���
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
		//���̰� 1�� ��� level_changed ++
		if (level_diff == 1) {
			level_changed++;
		}
		//���̰� 2�̻��� ��� false return 
		else if (level_diff >= 2) {
			return false;
		}
	}
	
	if (level_changed == 0) return true;

	//���� Ȯ��
	int left_count = 1;
	int can_go_left = 0;
	int right_count = 1;
	int can_go_right = 0;
	vector<bool> visited(n, 0);

	for (int i = 0; i < n - 1; i++) {
		//������ �������ٸ� ���θ� ���� �� �ִ��� Ȯ��
		//���� : ������ ���ӵ� ������ L �̻��ΰ�?

		//���ʿ��� ���� ���
		if (graph[row][i] == graph[row][i+1]) {
			left_count++;
		}
		else if (graph[row][i] < graph[row][i + 1]) {
			if (left_count >= l) {
				can_go_left++;
				//��ǥ�� �����Ѵ�.
				//i ���� i - l ���� ����
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

		//�����ʿ��� ���� ���
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