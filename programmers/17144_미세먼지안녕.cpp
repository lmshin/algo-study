#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int r, c, t;
int graph[51][51];
int graph_tmp[51][51] = { 0, };

vector<pair<int,int>> cleaner;
queue<pair<int, int>> dist;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void reset() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			graph_tmp[i][j] = 0;
		}
	}
}

void union_graph() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			graph[i][j] += graph_tmp[i][j];
		}
	}
}

void find_dist() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] != -1 && graph[i][j] > 0) {
				dist.push({ i,j });
			}
		}
	}
}

void spread_dist() {
	//퍼트리고
	reset();
	int sum;

	while (!dist.empty()) {
		int cur_r = dist.front().first;
		int cur_c = dist.front().second;
		dist.pop();

		//경계가 아니고
		sum = 0;
		//모든 칸에서 동시에 일어난다(서로 영향을 주면 안된다.)
		for (int i = 0; i < 4; i++) {
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];
			if (0 <= nc && nc < c && 0 <= nr && nr < r) {
				if (graph[nr][nc] == -1) continue; //공기청정기 만나면 pass

				graph_tmp[nr][nc] += graph[cur_r][cur_c] / 5;
				sum += graph[cur_r][cur_c] / 5;
			}
		}
		graph[cur_r][cur_c] -= sum;
	}
	//
	union_graph();
}

void active_cleaner() {
	// 위쪽 공기청정기 (반시계 방향)
	int top = cleaner[0].first;

	// 위쪽: 아래 → 위
	for (int i = top - 1; i > 0; i--)
		graph[i][0] = graph[i - 1][0];

	// 왼쪽 → 오른쪽 (맨 윗줄)
	for (int j = 0; j < c - 1; j++)
		graph[0][j] = graph[0][j + 1];

	// 위 → 아래 (오른쪽 열)
	for (int i = 0; i < top; i++)
		graph[i][c - 1] = graph[i + 1][c - 1];

	// 오른쪽 → 왼쪽 (공기청정기 줄)
	for (int j = c - 1; j > 1; j--)
		graph[top][j] = graph[top][j - 1];

	graph[top][1] = 0; // 공기청정기 바로 오른쪽은 항상 0


	// 아래쪽 공기청정기 (시계 방향)
	int bottom = cleaner[1].first;

	// 위 → 아래 (왼쪽 열)
	for (int i = bottom + 1; i < r - 1; i++)
		graph[i][0] = graph[i + 1][0];

	// 왼쪽 → 오른쪽 (맨 아랫줄)
	for (int j = 0; j < c - 1; j++)
		graph[r - 1][j] = graph[r - 1][j + 1];

	// 아래 → 위 (오른쪽 열)
	for (int i = r - 1; i > bottom; i--)
		graph[i][c - 1] = graph[i - 1][c - 1];

	// 오른쪽 → 왼쪽 (공기청정기 줄)
	for (int j = c - 1; j > 1; j--)
		graph[bottom][j] = graph[bottom][j - 1];

	graph[bottom][1] = 0;  // 공기청정기 바로 오른쪽은 항상 0

}


int check() {
	int answer = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] != -1 && graph[i][j] > 0) {
				answer += graph[i][j];
			}
		}
	}

	return answer;
}
int main() {

	
	//초기 입력
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == -1) {
				cleaner.push_back({ i,j });
			}
			else if (graph[i][j] > 0) {
				dist.push({ i,j });
			}
		}
	}

	//first 인 r 기준으로 오름차순 정렬, 0 번 인덱스가 위의 행, 1번이 아래 행
	sort(cleaner.begin(), cleaner.end());

	//t초 동안 반복
	for (int i = 0; i < t; i++) {
		spread_dist();

		active_cleaner();

		find_dist();
	}

	cout << check();
}