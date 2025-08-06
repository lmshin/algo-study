#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int graph[51][51] = { 0 };
int answer = 0;

//�ϵ�����
int dr[4][4] = {
	{ 0, 1, 0, -1 }, //�� �� �� �� ��
	{ -1 ,0 ,1, 0 }, //�� �� �� �� ��
	{ 0, -1, 0, 1 }, //�� �� �� �� ��
	{ 1, 0, -1, 0 }, //�� �� �� �� ��
};

int dc[4][4] = {
	{ -1, 0, 1, 0 }, //�� �� �� �� ��
	{ 0, -1, 0, 1 }, //�� �� �� �� ��
	{ 1, 0, -1, 0 }, //�� �� �� �� ��
	{ 0, 1, 0, -1 }, //�� �� �� �� ��
};

struct pos {
	int r;
	int c;
	int dir;
};

int main() {
	int n, m, r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	queue<pos> q;
	q.push({ r,c,d });
	int nexR;
	int nexC;
	int curR;
	int curC;
	int nexdir;
	bool isPushed;
	while (!q.empty()) {
		isPushed = false;
		curR = q.front().r;
		curC = q.front().c;
		int dir = q.front().dir;

		if (graph[curR][curC] == 0) {
			graph[curR][curC] = 2;
			answer++;
		}

		q.pop();

		//���� ����Ű�� �ִ� ������ �������� �������� ȸ���ؾ���
		for (int i = 0; i < 4; i++) {
			nexR = curR + dr[dir][i];
			nexC = curC + dc[dir][i];
			
			if (graph[nexR][nexC] == 0) {
				isPushed = true;
				 nexdir = (dir - 1 - i);
				if (nexdir < 0) nexdir += 4;
				q.push({ nexR ,nexC, nexdir });
				break;
			}
		}

		if (isPushed) continue;
		//�ڷΰ����ϴµ� �������� break;
		switch (dir) {
			case 0:
				nexR = curR + 1;
				nexC = curC;
				break;
			case 1:
				nexR = curR;
				nexC = curC - 1;
				break;
			case 2:
				nexR = curR - 1;
				nexC = curC;
				break;
			case 3:
				nexR = curR;
				nexC = curC + 1;
				break;
			default:
				break;
		}

		if (graph[nexR][nexC] == 1) {
			break;
		}
		else {
			q.push({ nexR ,nexC, dir });
		}
	}

	cout << answer;
}