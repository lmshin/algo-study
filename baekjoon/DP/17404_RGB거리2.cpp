
#include <vector>
#include <iostream>
using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, answer = 1e9;
    cin >> n;

    vector<vector<int>> cost(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; // R G B

    int first, last;
    vector<vector<int>> dp(n + 1, vector<int>(3, 1e9)); //최대값으로 초기화 하는게 맞나?

    for (int first = 0; first < 3; first++) {
        vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));
        dp[1][first] = cost[1][first];

        //그리고 dp 시작
        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1] + cost[i][0], dp[i - 1][2] + cost[i][0]);
            dp[i][1] = min(dp[i - 1][0] + cost[i][1], dp[i - 1][2] + cost[i][1]);
            dp[i][2] = min(dp[i - 1][0] + cost[i][2], dp[i - 1][1] + cost[i][2]);
        }

        //마지막 처리
        if (first == 0) {
            answer = min(answer, min(dp[n][1], dp[n][2]));
        }
        else if (first == 1) {
            answer = min(answer, min(dp[n][0], dp[n][2]));
        }
        else if (first == 2) {
            answer = min(answer, min(dp[n][0], dp[n][1]));
        }
    }

    cout << answer << "\n";
    return 0;
}
