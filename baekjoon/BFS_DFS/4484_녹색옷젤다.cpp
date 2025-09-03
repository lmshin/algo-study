#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int graph[126][126];
int dist[126][126];

int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct Pos{
	int distance;
	int x;
	int y;
	bool operator < (const Pos& other) const {
		return distance > other.distance;
	}
};

int find_way() {
	//0,0 에서 n-1, n-1 으로 가는 경로 중 최소값 찾기
	priority_queue<Pos> pq;
	pq.push({ graph[0][0], 0,0 });

	while (!pq.empty()) {
		
		int curX = pq.top().x;
		int curY = pq.top().y;
		int distance = pq.top().distance;
		pq.pop();

		if (curX == n - 1 && curY == n - 1) {
			return distance;
		}

		for (int i = 0; i < 4; i++) {
			int nexX = curX + dx[i];
			int nexY = curY + dy[i];
			int dis = graph[nexY][nexX];

			if (nexX < 0 || nexX >= n || nexY < 0 || nexY >= n) continue;

			//최소 경로로만 찾아가기
			if (dist[nexY][nexX] > distance + dis) {
				dist[nexY][nexX] = distance + dis;
				pq.push({ distance + dis,nexX,nexY });
			}
		}
	}

	return -1;
}

int main() {
	int cnt = 1;
	while (1) {
		
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
				dist[i][j] = 1e9;
			}
		}

		cout << "Problem " << cnt << ": " << find_way() << "\n";
		cnt++;
	}
}