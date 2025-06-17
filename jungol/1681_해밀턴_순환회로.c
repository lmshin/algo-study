#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
int n;
int graph[13][13];
int answer = INT_MAX;
bool check[13] = { 0, };

int min(int a, int b) {
	return a < b ? a : b;
}

void dfs(int start, int cost, int depth) {
	if (depth == n - 1) {//종료조건
		if (graph[start][0] == 0) {
			return;
		}
		else {
			answer = min(answer, cost + graph[start][0]);
		}
	}

	if (cost > answer) return;

	check[start] = true;
	for (int i = 0; i < n; i++) {
		if (i != start && !check[i] && graph[start][i] != 0) {
			dfs(i, cost + graph[start][i], depth + 1);
		}
	}
	check[start] = false;
}

int main() {
	//입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	//계산
	for (int i = 1; i < n; i++) {
		check[0] = true;
		if (graph[0][i] != 0) {
			dfs(i, graph[0][i], 1);
		}
		check[0] = false;
	}

	printf("%d", answer);
	//출력
	return 0;
}