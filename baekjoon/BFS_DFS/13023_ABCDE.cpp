#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<bool> visited;
vector<vector<int>> graph;
int n, m;
bool flag;

int dfs(int start, int cnt) {
	if (cnt >= 5) {
		flag = true;
		return 1;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		int nextNode = graph[start][i];
		//������ ��尡 �̹� �湮�� �� �ִٸ� continue
		if (visited[nextNode]) continue;

		//visited �迭�� true�� �ٲٰ� ����.
		visited[nextNode] = true;
		dfs(nextNode, cnt + 1);
		visited[nextNode] = false;
	}

	return 0;
}

int main() {
	//�Է�
	cin >> n >> m;
	graph.resize(n + 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		visited.assign(n + 1, 0);
		visited[i] = true;
		//�� ��忡�� dfs�� �����ϸ� 5���� ��尡 ����Ǿ��ִ��� Ȯ���Ѵ�.
		flag = false;
		dfs(i, 1);
		if(flag) {
			cout << "1";
			return 0;
		} 
	}
	
	cout << "0";
	return 0;
}