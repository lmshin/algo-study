#include<iostream>
#include<vector>
using namespace std;
int graph[1025][1025] = {0};
int sum_graph[1025][1025] = {0};
int n,m;

//
void make_sum_graph() {
	for (int i = 2; i <= n; i++) {
		sum_graph[1][i] += sum_graph[1][i - 1];
		sum_graph[i][1] += sum_graph[i - 1][1];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			sum_graph[i][j] = sum_graph[i][j] + sum_graph[i][j - 1] + sum_graph[i - 1][j] - sum_graph[i - 1][j - 1];
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> n >> m;

	//map 입력과 sum_map을 동시에 입력받는다. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			sum_graph[i][j] = graph[i][j];
		}
	}

	make_sum_graph();

	
	//행 열이므로 반대로 입력 받는다.
	int x1, x2, y1, y2;
	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << sum_graph[y2][x2] - sum_graph[y1 - 1][x2] - sum_graph[y2][x1 - 1] + sum_graph[y1 - 1][x1 - 1] << "\n";
	}
}