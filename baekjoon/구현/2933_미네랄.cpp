#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
int dr[4] = { 0,1,0,-1 }; //남 동 북 서
int dc[4] = { 1,0,-1,0 };
int border_r, border_c;
char arr[101][101];
bool visited[101][101];

struct pos {
    int r;
    int c;
};


void clear_visited() {
    for (int i = 0; i < border_r; i++) {
        for (int j = 0; j < border_c; j++) {
            visited[i][j] = false;
        }
    }
}

void input() {
    cin >> border_r >> border_c;
    for (int i = 0; i < border_r; i++) {
        for (int j = 0; j < border_c; j++) {
            cin >> arr[i][j];
        }
    }
}

bool comp(pos a, pos b) {
    if (a.c == b.c) {
        return a.r < b.r;
    }
    else {
        return a.c < b.c;
    }
}

bool comp2(pos a, pos b) {
    if (a.c == b.c) {
        return a.r > b.r;
    }
    else {
        return a.c < b.c;
    }
}

void down_cluster(vector<pos>& cluster) {
    //각 col 마다 최소의 row 을 구해야 함
    unordered_map<int, int> minRowAtCol;
    sort(cluster.begin(), cluster.end(), comp);

    for (auto Pos : cluster) {
        minRowAtCol[Pos.c] = Pos.r;
        arr[Pos.r][Pos.c] = '.';
    }

    sort(cluster.begin(), cluster.end(), comp2);
    //col당 가장낮은 row 들이 땅에 닿지 않는다면

    int cnt = 0;
    while (1) {
        bool flag = true;
        for (auto Pos : minRowAtCol) {

            int c = Pos.first;
            int r = Pos.second;

            if (arr[r + 1][c] == border_r-1 || arr[r + 1][c] == 'x') {
                flag = false;
                break;
            }

            minRowAtCol[c]++;
        }

        if (flag) {
            cnt++;
        }
        else {
            break;
        }
    }

    //cnt 만큼 별좌표 이동 후 그리기
    for (auto Pos : cluster) {
        arr[Pos.r+cnt][Pos.c] = 'x';
    }
}

bool is_connected_floor(int r, int c) {
    //x,y 에서부터 bfs 를 수행해 가면서 바닥(r==1)으로 이어져있는지 확인한다.
    vector<queue<pos>> vq(4);
    arr[r][c] = '.';

    for (int i = 0; i < 4; i++) {
        int nexR = r + dr[i];
        int nexC = c + dc[i];
        if (arr[nexR][nexC] == 'x') {
            vq[i].push({ nexR,nexC });
        }
    }

    for (queue<pos> q : vq) {
        bool is_connected = false;
        vector<pos> cluster;
        
        if (q.empty()) continue;
        clear_visited();

        while (!q.empty()) {
            int curR = q.front().r;
            int curC = q.front().c;
            cluster.push_back({ curR,curC });
            q.pop();

            if (curR == border_r-1) { //땅에 도달하는 경우
                is_connected = true;
            }

            for (int i = 0; i < 4; i++) {
                int nexR = curR + dr[i];
                int nexC = curC + dc[i];

                //방문한적없고 미네랄이라면 q에 push
                if (nexC < 0 || nexC >= border_c || nexR < 0 || nexR >= border_r) continue;

                if (!visited[nexR][nexC] && arr[nexR][nexC] == 'x') {
                    visited[nexR][nexC] = true;
                    q.push({ nexR,nexC });
                }
            }
        }

        if (is_connected) continue;

        else {
            //cluster down 시키기
            down_cluster(cluster);
        }
    }


    return false;
}

void shot(int height, int left_or_right) {
    if (left_or_right % 2 == 0) {//왼쪽에서 발사
        for (int i = 0; i < border_c; i++) {
            if (arr[border_r - height][i] == 'x') {
                is_connected_floor(border_r - height, i);
                break;
            }
        }
    }
    else {//오른쪽에서 발사
        for (int i = border_c -1; i >= 0; i--) {
            if (arr[border_r - height][i] == 'x') {
                is_connected_floor(border_r - height, i);
                break;
            }
        }
    }
}

void solve() {
    int n, height;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> height;
        shot(height, i);
    }

}

void printArr() {
    for (int i = 0; i < border_r; i++) {
        for (int j = 0; j < border_c; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

int main() {
    input();
    solve();
    printArr();

    return 0;
}