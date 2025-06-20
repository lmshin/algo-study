#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 102
using namespace std;
int n, cx, cy, nx, ny, min_height = 101, max_height = -1;
int map[MAX][MAX] = { 0 };
int tmp_map[MAX][MAX] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void input() { //ũ�� 2 ��Ʈ���̵�
	int input;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
				map[i][j] = 0;
			}
			else {
				cin >> input;
				map[i][j] = input;
				min_height = min(min_height, input);
				max_height = max(max_height, input);
			}
		}
	}
}

//����� �ʱ�ȭ
void copyMap() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}

//���̰� �־������� ���� ��� ���� ����� �Լ�
void makeWaterBomb(int height) {
	
	//��� ������ 0���� ǥ��
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (tmp_map[i][j] <= height) {
				tmp_map[i][j] = 0;
			}
		}
	}
}

//�ش� ��ǥ���� BFS�� �������� �����
void bfs(int x, int y, int count) {

	tmp_map[y][x] = count;
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));

	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (tmp_map[ny][nx] > 0) {
				tmp_map[ny][nx] = count;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

//������� �ʿ��� ���������� ������ ���ϴ� �Լ�
int getSafeRegions() {
	int count = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (tmp_map[i][j] > 0) {//���� ����� ���� ������ ����� ǥ�õǾ�����
				count--;
				bfs(j, i, count);
			}
		}
	}

	return count;
}

int main(){
	//�Է�
	input();

	//���
	vector<int> results;
	for (int height = min_height; height < max_height; height++) {//������ ���� ���ʿ����

		//������ ���� �����Ͽ� ���ο� ���� ����� �Լ�
		copyMap();

		//���̰� �־������� ���� ��� ���� ����� �Լ�
		makeWaterBomb(height);

		//������� �ʿ��� ���������� ������ ���ϴ� �Լ�
		int result = getSafeRegions();
		results.push_back(result);
	}
	

	//���
	if(results.size() == 0){ //���̰� ��� �Ȱ��� ���
		cout << "1" << "\n";
	}
	else {
		int answer = abs(*min_element(results.begin(), results.end()));
		cout << answer << "\n";
	}
	
	return 0;
}