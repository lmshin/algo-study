#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int N, M;
vector<Point> houses;
vector<Point> chickens;
vector<int> selected;
int answer = 1e9;

int dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

//idx는 조합을 위한 parameter
void dfs(int idx, int cnt) {
    if (cnt == M) {
        int city_dist = 0;
        for (auto& house : houses) {
            int min_dist = 1e9;
            //선택된 치킨집에 대해 거리측정
            for (int i = 0; i < M; i++) {
                int cd = dist(house, chickens[selected[i]]);
                min_dist = min(min_dist, cd);
            }
            city_dist += min_dist;
        }
        answer = min(answer, city_dist);
        return;
    }

    if (idx == (int)chickens.size()) return;

    // 선택
    selected.push_back(idx);
    dfs(idx + 1, cnt + 1);

    // 선택하지 않음
    selected.pop_back();
    dfs(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val; 
            cin >> val;
            if (val == 1) houses.push_back({ i, j });
            else if (val == 2) chickens.push_back({ i, j });
        }
    }

    dfs(0, 0);

    cout << answer << "\n";
    return 0;
}
