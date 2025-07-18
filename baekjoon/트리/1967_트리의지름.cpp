#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void bfs(int startNode, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
	queue<pair<int, int>> q;
	q.push(make_pair(startNode, 0));
	distance[startNode] = -1;

	while (!q.empty()) {
		int curNode = q.front().first;
		int sum_of_distance = q.front().second;
		q.pop();

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i].first;
			int cur_distance_next = sum_of_distance + graph[curNode][i].second;
			if (distance[nextNode] == 0) {
				distance[nextNode] = cur_distance_next;
				q.push(make_pair(nextNode, cur_distance_next));
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int start, end, dis;
	vector<vector<pair<int, int>>> graph(n + 1);
	//vector<vector<int>> distance(n + 1, vector<int>(n + 1, 0)); -> 2�������� �޸��ʰ�
	vector<int> distance(n + 1); //1�������ε� ����
	for (int i = 0; i < n-1; i++) {
		cin >> start >> end >> dis;
		graph[start].push_back(make_pair(end, dis));
		graph[end].push_back(make_pair(start, dis));
	}


	int answer = 0;
	for (int i = 1; i <= n; i++) {
		bfs(i, graph, distance);

		//�ִ�Ÿ� ���ϰ�, distance�� �ʱ�ȭ
		for (int j = 1; j <= n; j++) {
			answer = max(answer, distance[j]);
			distance[j] = 0;
		}
	}

	cout << answer;
}