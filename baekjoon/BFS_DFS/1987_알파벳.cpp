#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
char graph[21][21];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
//O(1) 로 searching 할수있는 key value 자료구조 필요 -> map? hash?
unordered_map<char, bool> checked;
bool visited[26];

int r, c;
string s;
int answer = 0;

void dfs(int x, int y, int cnt) {
	if (answer < cnt) answer = cnt;

	visited[graph[y][x] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < c && 0 <= ny && ny < r && !visited[graph[ny][nx] - 'A']) {
			
			dfs(nx, ny, cnt+1);
			
		}
	}

	visited[graph[y][x] - 'A'] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			graph[i][j] = s[j];
		}
	}

	dfs(0, 0, 1);

	cout << answer;
}