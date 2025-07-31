#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
bool visited[8][8][9] = { false }; // x, y, �ð�

struct pos {
    int x;
    int y;
    int time;
};

bool bfs(vector<string>& board) {
    queue<pos> q;
    q.push({0, 7, 0});

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int curT = q.front().time;
        q.pop();

        if (curT >= 8) {
            return true;
        }

        for (int i = 0; i < 9; i++) {
            
            //�̵��ϱ�
            int nexX = curX + dx[i];
            int nexY = curY + dy[i];
            int nexT = curT + 1;
            if (visited[nexY][nexX][nexT]) continue;

            //board ���� ���̸� push x
            if (nexX < 0 || nexX >= 8 || nexY < 0 || nexY >= 8) continue;

            //�̵��ߴµ� #�̸� push x
            if ((nexY - curT) >= 0 && board[nexY - curT][nexX] == '#') continue;

            //�̵��ߴµ� �����򸮸� push x
            if ((nexY - curT - 1) >= 0 && board[nexY - curT - 1][nexX] == '#') continue;

            visited[nexY][nexX][nexT] = true;
            q.push({ nexX , nexY, nexT });
        }
    }

    return false;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    //8�ʵ��� ��Ƴ����� 1���
    cout << bfs(board) << "\n";
    return 0;
}
