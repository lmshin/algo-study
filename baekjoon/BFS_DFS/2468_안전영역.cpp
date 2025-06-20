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

void input() { //크기 2 스트라이드
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

//복사맵 초기화
void copyMap() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}

//높이가 주어졌을때 물에 잠긴 맵을 만드는 함수
void makeWaterBomb(int height) {
	
	//잠긴 영역을 0으로 표시
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (tmp_map[i][j] <= height) {
				tmp_map[i][j] = 0;
			}
		}
	}
}

//해당 좌표에서 BFS로 안전영역 만들기
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

//만들어진 맵에서 안전영역의 개수를 구하는 함수
int getSafeRegions() {
	int count = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (tmp_map[i][j] > 0) {//물에 잠기지 않은 영역만 양수로 표시되어있음
				count--;
				bfs(j, i, count);
			}
		}
	}

	return count;
}

int main(){
	//입력
	input();

	//계산
	vector<int> results;
	for (int height = min_height; height < max_height; height++) {//다잠기는 경우는 할필요없음

		//기존의 맵을 복사하여 새로운 맵을 만드는 함수
		copyMap();

		//높이가 주어졌을때 물에 잠긴 맵을 만드는 함수
		makeWaterBomb(height);

		//만들어진 맵에서 안전영역의 개수를 구하는 함수
		int result = getSafeRegions();
		results.push_back(result);
	}
	

	//출력
	if(results.size() == 0){ //높이가 모두 똑같은 경우
		cout << "1" << "\n";
	}
	else {
		int answer = abs(*min_element(results.begin(), results.end()));
		cout << answer << "\n";
	}
	
	return 0;
}