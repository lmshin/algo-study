#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int node, vector<vector<int>> map, bool check[], int &count) {
	check[node] = true;

	for (int i = 1; i <= map.size(); i++) {
		if (map[node][i] && !check[i]) {
			(*count)++;
			dfs(i, map, check, count);
		}
	}

	return;
}

int main() {
	int numComputer, v;
	cin >> numComputer >> v;
	vector<vector<int>> map(numComputer + 1, vector<int>(numComputer + 1, 0));
	vector<bool> check[numComputer + 1] = { 0, };

	int start, end;
	for (int i = 0; i < v; i++) {
		cin >> start >> end;
		map[start][end] = 1;
		map[end][start] = 1;
	}

	int count = 0;
	dfs(1,mapm,check,&count);
	
	return 0;
}