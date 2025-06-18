#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100
int n, m, h;
int arr[MAX][MAX][MAX] = {0};
bool visited[MAX][MAX][MAX] = {0};
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

typedef struct {
	int x;
	int y;
	int z;
} position;

queue<position> q;

void input() {
	int tmp;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tmp;
				arr[i][j][k] = tmp;
				if (tmp == 1) {
					position p = { k,j,i };
					visited[i][j][k] = true;
					q.push(p);
				}
			}
		}
	}
}

void getAnswer() {
	int tmp, answer = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				tmp = arr[i][j][k];
				if (tmp == 0) {
					cout << "-1" << "\n";
					return;
				}
				else {
					answer = max(answer, tmp);
				}
			}
		}
	}
	cout << answer-1 << "\n";
	return;
}


void print() {
	int tmp;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cout << arr[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void bfs() {//토마토익히기
	int current_x, currnet_y, currnet_z;
	int next_x, next_y, next_z;

	while (!q.empty()) {
		position pos = q.front();
		int current_x = pos.x;
		int current_y = pos.y;
		int current_z = pos.z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			next_x = current_x + dx[i];
			next_y = current_y + dy[i];
			next_z = current_z + dz[i];
			//방문한 적이 없다면 범위내에있고, 그리고 0 이라면 
			if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n && 0 <= next_z && next_z < h && !visited[next_z][next_y][next_x]) {
				if (arr[next_z][next_y][next_x] == -1) {
					continue;
				}
				else {
					position p = { next_x,next_y,next_z };
					arr[next_z][next_y][next_x] = arr[current_z][current_y][current_x] + 1;
					visited[next_z][next_y][next_x] = true;
					q.push(p);
				}
			}
		}
	}
}

int main() {
	//입력
	input();

	//계산
	bfs();

	//출력
	printf("\n");
	print();
	getAnswer();
}


//for (int = 2; i <= n; i++) {
//	if (!visited[i] && arr[cur][i] != 0) {
//		visited[i] = 1;
//		dfs(cnt + 1, i, cost + arr[cur][i]);
//		visited[i] = 0;
//	}
//}