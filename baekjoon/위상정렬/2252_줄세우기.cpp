#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	int start, end;
	vector<int> in_degree(n + 1, 0);
	vector<vector<int>> map(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		map[start].push_back(end);
		in_degree[end]++;
	}
	
	in_degree[0] = -1;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			in_degree[i] = -1;
		}
	}
	
	while (!q.empty()) {
		int cur = q.front();
		cout << cur << " ";
		q.pop();
		
		for (int i = 0; i < map[cur].size(); i++) {
			if (in_degree[map[cur][i]] > 0){
				in_degree[map[cur][i]]--;
			}

			if (in_degree[map[cur][i]] == 0) {
				q.push(map[cur][i]);
				in_degree[map[cur][i]] = -1;
			}
		}
	}

	return 0;
}