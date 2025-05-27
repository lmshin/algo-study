#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1001;
bool check_dfs[MAX] = { 0, };
bool check_bfs[MAX] = { 0, };
vector<vector<int>> vMap(MAX);

void dfs(int start) {
	check_dfs[start] = 1;
	cout << start << " ";
	for (int i = 0; i < vMap[start].size(); i++) {
		int next = vMap[start][i];
		if (!check_dfs[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check_bfs[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << " ";

		for (int i = 0; i < vMap[current].size(); i++) {
			int next = vMap[current][i];
			if (!check_bfs[next]) {
				q.push(next);
				check_bfs[next] = true;
			}
		}
	}
}

int main() {

	int n, m, v;
	cin >> n >> m >> v;
	
	//리스트로
	int start, end;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		vMap[start].push_back(end);
		vMap[end].push_back(start);
	}

	for (int i = 1; i <= n; i++) {
		sort(vMap[i].begin(), vMap[i].end());
	}

	dfs(v);
	cout << endl;
	bfs(v);
	cout << endl;

	return 0;
}
