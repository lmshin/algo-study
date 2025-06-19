#include<stdio.h>

void sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int dfs(int (*visited)[27], int (*map)[27], int i, int j) {
	if (visited[i][j] == 1 || map[i][j] == 0) {
		return 0;
	}

	visited[i][j] = 1;

	return 1 + dfs(visited, map, i + 1, j) + dfs(visited, map, i - 1, j) + dfs(visited, map, i, j + 1) + dfs(visited, map, i, j - 1);
}

int main() {
	int n;
	int cnt = 0;
	int map[27][27] = { 0, };
	int visited[27][27] = { 0, };
	int answer[312] = { 0, };

	//입력
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//DFS 실행
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(visited[i][j] == 0 && map[i][j] == 1) {
				answer[cnt++] = dfs(visited, map, i, j);
			}
		}
	}

	sort(answer, cnt);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", answer[i]);
	}
	
	return 0;
}