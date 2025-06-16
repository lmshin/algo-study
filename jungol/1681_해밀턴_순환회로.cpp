#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& map, vector<bool>& check, int start, int n, int depth, int cost, int& result) {
	if (depth == n) {
		if (map[start][0] > 0) { // 회사로 돌아가는 길이 있을 때만
			result = min(result, cost + map[start][0]);
		}
		return;
	}

	for (int i = 1; i < n; i++) { // 0은 출발지이므로 제외
		if (!check[i] && map[start][i] > 0) {
			check[i] = true;
			dfs(map, check, i, n, depth + 1, cost + map[start][i], result);
			check[i] = false;
		}
	}
}



void dfs2(vector<vector<int>>& map, vector<bool>& check, int start, int n, int depth, int cost, int& result) {

	if (depth == n) {//재귀함수
		result = min(result, cost + map[start][0]);
		return;
	}

	for (int i = 0; i < n; i++) {//dfs 들어가는 부분,
		if (!check[i] && i != start && i != 0) {
			int temp = map[start][i];
			check[i] = true;
			dfs(map, check, i, n, depth + 1, cost + temp, result);
			check[i] = false;
		}
	}

	return;
}

//이건 그냥 다 도는거고 //회사로 돌아와야 함,

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
	
	//최소비용 구하기, 이거 dfs 아닌가?
	cout << answer;

	return 0;
}