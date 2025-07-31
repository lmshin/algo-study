#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int v, e;

int bfs(int start_node, vector<vector<pair<int, int>>>& graph) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> check(v + 1, false);
	pq.push(make_pair(0, start_node));
	//min heap을 이용해서, 최소값들로만 트리를 먼저 구성한다.
	//min_heap 쓰면 알아서 최소트리로 구성됨
	//지금까지 만든 트리에서 가장 적은 비용으로 연결 가능한 정점을 하나씩 계속 추가한다
	//꺼내진 것들끼리 tree를 구성하면 된다.
	int total = 0;
	int count = 0;

	while (!pq.empty()) {
		int cur_node = pq.top().second;
		int cur_weight = pq.top().first;
		pq.pop();

		if (check[cur_node]) continue;

		check[cur_node] = true;
		total += cur_weight;
		count++;
		
		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].first;
			int next_weight = graph[cur_node][i].second;
			if (!check[next_node]) {
				pq.push(make_pair(next_weight, next_node));
			}
		}
	}

	return (count == v) ? total : -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	//input
	int start, end, weight;
	vector<vector<pair<int, int>>> graph(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> start >> end >> weight;
		graph[start].push_back(make_pair(end, weight));
		graph[end].push_back(make_pair(start, weight));
	}

	int answer = bfs(1, graph);
	
	cout << answer;

	return 0;
}