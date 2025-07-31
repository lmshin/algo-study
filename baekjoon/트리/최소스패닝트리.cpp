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
	//min heap�� �̿��ؼ�, �ּҰ���θ� Ʈ���� ���� �����Ѵ�.
	//min_heap ���� �˾Ƽ� �ּ�Ʈ���� ������
	//���ݱ��� ���� Ʈ������ ���� ���� ������� ���� ������ ������ �ϳ��� ��� �߰��Ѵ�
	//������ �͵鳢�� tree�� �����ϸ� �ȴ�.
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