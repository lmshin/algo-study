#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int n, m;
int graph[9][9];
int graph_tmp[9][9];
bool visit[9][9];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int answer = 0;
queue<pair<int, int>> ori_q;

void clear() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = false;
			graph_tmp[i][j] = graph[i][j];
		}
	}
}

void check_max_area() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph_tmp[i][j] == 0 ) cnt++;
		}
	}

	answer = max(answer, cnt);
	//cout << answer << "\n";
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		cout << graph_tmp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//cout << "\n";
	//cout << "\n";
}


void input() {
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				ori_q.push({ i,j });
			}
		}
	}
}

//2로부터 
void bfs() {
	queue<pair<int, int>> q = ori_q;
	clear();

	while (!q.empty()) {
		int y = q.front().first; 
		int x = q.front().second;
		q.pop();

		//처음 q에 들어있는 것들을 위한 코드
		visit[y][x] = true;

		for (int i = 0; i < 4; i++) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (graph_tmp[nexty][nextx] == 1 || graph_tmp[nexty][nextx] == 2) continue;
			if (nextx < 1 || nextx > m || nexty < 1 || nexty > n) continue;
			
			graph_tmp[nexty][nextx] = 2;
			q.push({ nexty, nextx });
		}
	}

	check_max_area();
}

//map을 돌면서 랜덤으로 3개의 벽을 세운다.
void dfs(int x, int y, int count) {
	for (int i = y; i <= n; i++) {
		for (int j = (i == y ? x : 1); j <= m; j++) {
			if (graph[i][j] == 0 && count < 3) {
				graph[i][j] = 1;
				count++;
				if (count == 3) bfs();
				else dfs(j, i, count);
				count--;
				graph[i][j] = 0;

			}
		}
	}
}

int main() {
	input();
	dfs(1,1, 0);
	cout << answer;
}