#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& map, vector<bool>& check, int start, int n, int depth, int cost, int& result) {
	if (depth == n) {
		if (map[start][0] > 0) { // ȸ��� ���ư��� ���� ���� ����
			result = min(result, cost + map[start][0]);
		}
		return;
	}

	for (int i = 1; i < n; i++) { // 0�� ������̹Ƿ� ����
		if (!check[i] && map[start][i] > 0) {
			check[i] = true;
			dfs(map, check, i, n, depth + 1, cost + map[start][i], result);
			check[i] = false;
		}
	}
}



void dfs2(vector<vector<int>>& map, vector<bool>& check, int start, int n, int depth, int cost, int& result) {

	if (depth == n) {//����Լ�
		result = min(result, cost + map[start][0]);
		return;
	}

	for (int i = 0; i < n; i++) {//dfs ���� �κ�,
		if (!check[i] && i != start && i != 0) {
			int temp = map[start][i];
			check[i] = true;
			dfs(map, check, i, n, depth + 1, cost + temp, result);
			check[i] = false;
		}
	}

	return;
}

//�̰� �׳� �� ���°Ű� //ȸ��� ���ƿ;� ��,

int main() {
	int n;
	cin >> n;

	// n <= 13;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	int answer = 9999999;
	int depth = 0;
	vector<bool> check(n, 0);
	dfs(map, check, 0, n, 1,0, answer);
	
	//�ּҺ�� ���ϱ�, �̰� dfs �ƴѰ�?
	cout << answer;

	return 0;
}