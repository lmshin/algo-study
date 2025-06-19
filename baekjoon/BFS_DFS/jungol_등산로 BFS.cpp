#include<iostream>
#include<vector>
#include<queue>

#define MAX 102 //padding 해준다
using namespace std;
int n, mountain_x, mountain_y, next_x, next_y, tmp, next_value, current_value;
int map[MAX][MAX] = { 0 };
int cost_map[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { 0 };

int answer = 0x7FFFFFFF;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void bfs(int x, int y) {
	//정상으로부터 최소값 map을 만들어 나간다.
	int diff, next_value, current_value, cur_x, cur_y, nex_x, nex_y, cost = 0;
	cost_map[y][x] = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();

		//조건에 맞는 경우 push, 이 문제에서의 조건이란 cost_min 값보다 작은 cost 를 가진 경로를 찾은 경우를 말함
		for (int i = 0; i < 4; i++) {
			nex_x = cur_x + dx[i];
			nex_y = cur_y + dy[i];
			
			if (map[nex_y][nex_x] != 0) {
				
				if (nex_x == x) {//정상은 경로에 포함되면 안됨
					if (nex_y == y) {
						continue;
					}
				}

				cost = 0;

				next_value = map[nex_y][nex_x];
				current_value = map[cur_y][cur_x];

				if (next_value < current_value) {//값은 낮아지지만 실제로는 등산인 경우
					diff = current_value - next_value;
					cost = diff * diff;
				}
				else if (next_value > current_value) {//값은 높아지지만 실제로는 하산인 경우
					diff = next_value - current_value;
					cost = diff;
				}
				else {//유지
					cost = 0;
				}
				int tmp = cost_map[cur_x][cur_y];
				if (cost_map[nex_y][nex_x] > cost_map[cur_y][cur_x] + cost) {//기존의 cost 값보다 더 작을때만 q에 push
					cost_map[nex_y][nex_x] = cost_map[cur_y][cur_x] + cost;
					q.push(make_pair(nex_x, nex_y));
				}

			}

		}
		
	}

	//답찾기, 경계에 대해서는 진입할때의 값을 더해주어야 함
	int answer = 0x7FFFFFFF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 || i == n || j == 1 || j == n) {
				cost_map[i][j] += map[i][j] * map[i][j];
				answer = min(answer, cost_map[i][j]);
			}
		}
	}

	cout << answer << "\n";

	return;
}

void input() {
	cin >> n >> mountain_y >> mountain_x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cost_map[i][j] = 0x7FFFFFFF;
		}
	}
}

void map_print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void cost_map_print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << cost_map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	//입력
	input();

	//계산
	bfs(mountain_x,mountain_y);

	//출력
	cout << "\n"; 
	cost_map_print();
}