#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, a, b, c;
vector<vector<pair<int,int>>> graph;

struct Node {
	int distance;
	int number;
	int maxValue;
	bool operator < (const Node& other) const {
		return this->distance > other.distance;
	}
};

void input() {
	cin >> n >> m >> a >> b >> c;
	graph.resize(n + 1);

	int start, end, value;
	for (int j = 0; j < m; j++) {
		cin >> start >> end >> value;
		graph[start].push_back({ end,value });
		graph[end].push_back({ start,value });
	}
}


//A에서 B로 가는데 경로의 최대값이 pivot 이상이면 취소한다.
//A에서 B로 가는데 드는 비용이 C 이하이면 취소한다.
int dijkstra(int pivot) {
	priority_queue<Node> pq;
	vector<int> d(n + 1, 0x7fffffff);
	bool canVisit = false;
	d[a] = 0;
	pq.push({ 0,a,0 });
	int answer = 0x7fffffff;

	while(!pq.empty()){
		int distance = pq.top().distance;
		int curNode = pq.top().number;
		int maxValue = pq.top().maxValue;
		int tmp = maxValue;

		pq.pop();
		
		//cout << "distance : " << distance << " curNode : " << curNode << " maxValue : " << maxValue << "\n";
		//if (d[curNode] != maxValue) continue;

		if (curNode == b && distance <= c) {
			answer = min(answer, maxValue);
			canVisit = true;
		}

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i].first;
			int dis = graph[curNode][i].second;
			maxValue = tmp;
			maxValue = max(maxValue, dis);

			if (d[nextNode] > distance + dis && dis <= pivot) {
				d[nextNode] = distance + dis;
				pq.push({ distance + dis , nextNode, maxValue });
			}
		}
	}

	if (!canVisit) answer = -1;
	return answer;
}

int binary_search() {
	int start=1, end=20, pivot;
	int res = -1, d;

	while (start <= end) {
		pivot = (start + end) / 2;
		d = dijkstra(pivot);
		if (d != -1) {
			res = pivot;
			end = pivot - 1;
		}
		else {
			start = pivot + 1;
		}
	}

	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	input();
	cout << binary_search();
}