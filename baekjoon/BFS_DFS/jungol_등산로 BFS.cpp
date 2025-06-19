#include<iostream>
#include<vector>
#include<queue>

#define MAX 102 //padding ���ش�
using namespace std;
int n, mountain_x, mountain_y, next_x, next_y, tmp, next_value, current_value;
int map[MAX][MAX] = { 0 };
int cost_map[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { 0 };

int answer = 0x7FFFFFFF;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void bfs(int x, int y) {
	//�������κ��� �ּҰ� map�� ����� ������.
	int diff, next_value, current_value, cur_x, cur_y, nex_x, nex_y, cost = 0;
	cost_map[y][x] = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();

		//���ǿ� �´� ��� push, �� ���������� �����̶� cost_min ������ ���� cost �� ���� ��θ� ã�� ��츦 ����
		for (int i = 0; i < 4; i++) {
			nex_x = cur_x + dx[i];
			nex_y = cur_y + dy[i];
			
			if (map[nex_y][nex_x] != 0) {
				
				if (nex_x == x) {//������ ��ο� ���ԵǸ� �ȵ�
					if (nex_y == y) {
						continue;
					}
				}

				cost = 0;

				next_value = map[nex_y][nex_x];
				current_value = map[cur_y][cur_x];

				if (next_value < current_value) {//���� ���������� �����δ� ����� ���
					diff = current_value - next_value;
					cost = diff * diff;
				}
				else if (next_value > current_value) {//���� ���������� �����δ� �ϻ��� ���
					diff = next_value - current_value;
					cost = diff;
				}
				else {//����
					cost = 0;
				}
				int tmp = cost_map[cur_x][cur_y];
				if (cost_map[nex_y][nex_x] > cost_map[cur_y][cur_x] + cost) {//������ cost ������ �� �������� q�� push
					cost_map[nex_y][nex_x] = cost_map[cur_y][cur_x] + cost;
					q.push(make_pair(nex_x, nex_y));
				}

			}

		}
		
	}

	//��ã��, ��迡 ���ؼ��� �����Ҷ��� ���� �����־�� ��
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
	//�Է�
	input();

	//���
	bfs(mountain_x,mountain_y);

	//���
	cout << "\n"; 
	cost_map_print();
}