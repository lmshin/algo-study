#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int node, const vector<vector<int>> &map, vector<bool>& check, int &count) {
	check[node] = true;

	for (int i = 1; i < map.size(); i++) {
		if (map[node][i] && !check[i]) {
			count++;
			dfs(i, map, check, count);
		}
	}

	return;
}

void bfs(int node, const vector<vector<int>>& map, vector<bool> &check, int &count)  {
	check[node] = true;

	queue<int> q; 
	q.push(node);

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();
		for (int i = 1; i < map.size(); i++) {
			if (!check[i] && map[currentNode][i]) {
				check[i] = true;
				q.push(i);
				count++;
			}
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false); // C++ 스트림과 C 스트림의 동기화 해제
	cin.tie(NULL); // cin과 cout의 묶임을 해제하여 출력 버퍼 비우기 방지


	int numComputer, v;
	cin >> numComputer >> v;
	vector<vector<int>> map(numComputer + 1, vector<int>(numComputer + 1, 0));
	vector<bool> check(numComputer + 1, false);

	int start, end;
	for (int i = 0; i < v; i++) {
		cin >> start >> end;
		map[start][end] = 1;
		map[end][start] = 1;
	}

	int count = 0;
	bfs(1,map,check,count);
	
	cout << count;
	return 0;
}



void dfs(int start_node, const vector<vector<int>>& map, vector<bool>& check, int& count) {
	check[start_node] = true;

	for (int i = 1; i < map.size(); i++) {
		if (!check[i] && map[start_node][i]) {
			count++;
			int next_node = i;
			dfs(next_node, map, check, count);
		}
	}

	return;
}

void bfs(int start_node, const vector<vector<int>>& map, vector<bool>& check, int& count) {
	check[start_node] = true;
	queue<int> q;
	q.push(start_node);

	while (!q.empty()) {
		int current_node = q.front();
		q.pop();

		for (int i = 1; i < map[current_node].size(); i++) {
			if (!check[i] && map[current_node][i]) {
				int next_node = i;
				q.push(next_node);
				check[next_node] = true;
				count++;
			}
		}
	}

	return;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int computer_nodes,v;
	cin >> computer_nodes >> v;

	vector<vector<int>> map(computer_nodes + 1, vector<int>(computer_nodes + 1));
	vector<bool> check(computer_nodes + 1, 0);

	int start, end;
	for (int i = 0; i < v; i++) {
		cin >> start >> end;
		map[start][end] = 1;
		map[end][start] = 1;
	}

	int dfs_count = 0;
	dfs(1, map, check, count);

	int bfs_count = 0;
	//bfs(1, map, check, count);

	cout << dfs_count << endl;

	return 0;
}