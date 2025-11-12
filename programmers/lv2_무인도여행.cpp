#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

int r, c;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int graph[101][101];
int visited[101][101];
using namespace std;


//string  을 int 형식의 map으로 변환하기
void convert(vector<string>& maps) {
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'X') {
                graph[i][j] = -1;
            }
            else {
                graph[i][j] = maps[i][j] - '0';
            }
        }
    }
}

//-1 이 아닌 좌표에서 무인도 식량 카운트 시작
void bfs(vector<int>& answer, int y, int x) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    int sum = 0;


    //0,0 부터 끝까지 쭉 돌면서, 섬과 먹을거리를 다 찾는다.
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (graph[cy][cx] < 0) continue;

        sum += graph[cy][cx];
        graph[cy][cx] = -1;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < c && 0 <= ny && ny < r && graph[ny][nx] > 0) {
                //방문하고
                q.push({ nx,ny });
            }
        }
    }

    answer.push_back(sum);

    return;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    //일단 변환 먼저
    convert(maps);

    r = maps.size();
    c = maps[0].size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] > 0) {
                bfs(answer, i, j);
                cout << "y, x 좌표 : " << i << " " << j << "\n";
            }
        }
    }

    if (answer.size() == 0) {
        answer.push_back(-1);
    }
    else {
        sort(answer.begin(), answer.end());
    }


    return answer;
}