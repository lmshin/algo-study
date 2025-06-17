#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


//int 뿐만 아니라 다른 type pointer 들에 대해서도 적용이 가능함
//first > second 가 클 때 양수를 반환하면 오름차순, 
int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

void bfs(int x, int y, vector<vector<int>>& map, int& town_index, vector<vector<bool>>& check, vector<int>& answer){

	if (map[y][x] == 0 || check[y][x]) return;

	check[y][x] = true;
	map[y][x] = town_index;
	int n = map.size();
	int count = 1;
	queue<pair<int, int>> q;
	q.push(make_pair( x,y ));

	while (!q.empty()) {
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n && map[next_y][next_x] != 0 && !check[next_y][next_x]) {
				map[next_y][next_x] = town_index;
				check[next_y][next_x] = true;
				count++;
				q.push(make_pair(next_x, next_y));
			}
		}
	}

	answer.push_back(count);
	town_index++;
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> answer;
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<bool>> check(n, vector<bool>(n,false));

	string input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	int town_index = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfs(j, i, map, town_index, check,answer);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int num : answer) {
		cout << num << "\n";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}

	return 0;
}