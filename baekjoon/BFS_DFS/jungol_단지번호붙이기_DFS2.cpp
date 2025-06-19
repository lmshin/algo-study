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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int (*map)[27], int i, int j) {

}

int main() {

    int map[27][27] = { 0, };
    int numComplex[313] = {0,};
    int visitedFlag = 2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    //DFS ½ÃÀÛ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == 1) {
                dfs();
            }
        }
    }
}