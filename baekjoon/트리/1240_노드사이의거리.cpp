#include<iostream>
#include<queue>
#include<vector>
using namespace std;

 //가독성을 위해 pair 대신 struct 사용
typedef struct _node {
	int node_number;
	int sum_of_length;
}node;

void BFS(int startNode, vector<vector<pair<int,int>>>& graph, vector<vector<int>>& distance) {
	queue<node> q;
	q.push({ startNode,0 });
	distance[startNode][startNode] = -1; //백트래킹?

	while (!q.empty()) {
		int cur_node = q.front().node_number;
		int cur_length = q.front().sum_of_length;
		q.pop();

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int nextNode = graph[cur_node][i].first;
			int cur_distance_next = cur_length + graph[cur_node][i].second;

			if (distance[startNode][nextNode] == 0) { //방문한적없다면
				distance[startNode][nextNode] = cur_distance_next;
				q.push({ nextNode, cur_distance_next });
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> graph(n + 1);
	vector<vector<int>> distance(n + 1, vector<int>(n + 1, 0));
	int start, end, dis;
	for (int i = 0; i < n-1; i++) {
		cin >> start >> end >> dis;
		graph[start].push_back(make_pair(end, dis));
		graph[end].push_back(make_pair(start, dis));
	}

	for (int i = 1; i <= n; i++) {
		BFS(i, graph, distance);
	}

	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		cout << distance[start][end] << "\n";
	}

	return 0;
}