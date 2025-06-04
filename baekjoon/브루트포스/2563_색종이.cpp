#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> map(100, vector<int>(100, 0));

    int n, x, y;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                map[j][k] = 1;
            }
        }
    }

    int result = 0;
    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            if (map[j][k]) result++;
        }
    }

    cout << result << '\n';

    return 0;
}