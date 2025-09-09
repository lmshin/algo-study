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
		//가려는 노드가 이미 방문한 적 있다면 continue
		if (visited[nextNode]) continue;

		//visited 배열을 true로 바꾸고 들어간다.
		visited[nextNode] = true;
		dfs(nextNode, cnt + 1);
		visited[nextNode] = false;
	}

	return 0;
}

int main() {
	//입력
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
		//각 노드에서 dfs를 진행하며 5개의 노드가 연결되어있는지 확인한다.
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