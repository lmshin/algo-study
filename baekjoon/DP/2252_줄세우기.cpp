#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	int start, end;
	vector<int> in_degree(n + 1);
	vector<vector<int>> graph(n + 1);
	in_degree[0] = -1;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		graph[start].push_back(end);
		in_degree[end]++;
	}

	//graph 과 in_degree  vector 입력완료 이제부터 위상정렬 시작
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			in_degree[i] = -1; //0 처리한 노드는 -1로 초기화
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) { //진입차수 줄이기
			if (in_degree[graph[cur][i]] > 0) {
				in_degree[graph[cur][i]]--;
			}

			if (in_degree[graph[cur][i]] == 0) {
				q.push(graph[cur][i]);
				in_degree[graph[cur][i]] = -1; //0 처리한 노드는 -1로 초기화
			}
		}
	}

	return 0;
}