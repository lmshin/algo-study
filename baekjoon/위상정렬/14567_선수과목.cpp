#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> degree;
vector<int> answer;
vector<vector<int>> graph;
int n, m;
int a, b;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> n >> m;
	degree.resize(n + 1);
	answer.resize(n + 1);
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			answer[i] = 1;
		}
	}


	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int nextNode = graph[node][i];
			degree[nextNode]--;
			if (degree[nextNode] <= 0) {
				q.push(nextNode);
				answer[nextNode] = answer[node] + 1;

			}
		}
	}


	for (int i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}
}