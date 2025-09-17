#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Max = -1e9, Min = 1e9;
vector<int> numbers;

void dfs(int depth, int result, int a, int b, int c, int d) {
    if (depth == numbers.size() - 1) {
        Max = max(Max, result);
        Min = min(Min, result);
        return;
    }

    int next = numbers[depth + 1];

    if (a > 0) dfs(depth + 1, result + next, a - 1, b, c, d);
    if (b > 0) dfs(depth + 1, result - next, a, b - 1, c, d);
    if (c > 0) dfs(depth + 1, result * next, a, b, c - 1, d);
    if (d > 0) dfs(depth + 1, result / next, a, b, c, d - 1);
}

int main() {
    int n;
    cin >> n;

    numbers.resize(n);
    for (int i = 0; i < n; i++) cin >> numbers[i];

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    dfs(0, numbers[0], a, b, c, d);

    cout << Max << "\n" << Min;
}
