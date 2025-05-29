#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1001

int map[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N; // 💡 입력 순서: 열 M, 행 N
    cin >> M >> N;

    memset(check, false, sizeof(check));
    queue<pair<int, int>> q;

    // 입력 및 초기 큐 세팅
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({j, i});
                check[i][j] = true;
            }
        }
    }

    // BFS
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextX = curX + dx[dir];
            int nextY = curY + dy[dir];

            if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
                if (map[nextY][nextX] == 0 && !check[nextY][nextX]) {
                    map[nextY][nextX] = map[curY][curX] + 1;
                    check[nextY][nextX] = true;
                    q.push({nextX, nextY});
                }
            }
        }
    }

    // 결과 검사
    int maxDay = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
            maxDay = max(maxDay, map[i][j]);
        }
    }

    cout << maxDay - 1 << '\n'; // 첫날이 1이므로 -1
    return 0;
}
