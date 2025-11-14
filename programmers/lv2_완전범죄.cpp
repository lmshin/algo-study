#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 1e9;
    int len = info.size();
    vector<vector<int>> dp(len + 1, vector<int>(m, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= len; i++) {
        int a = info[i - 1][0];
        int b = info[i - 1][1];

        for (int j = 0; j < m; j++) {
            //if (dp[i-1][j] == INF) continue;

            // A啊 壬模 版快
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);

            // B啊 壬模 版快
            if (j + b < m)
                dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
        }
    }

    int answer = INF;
    for (int j = 0; j < m; j++)
        answer = min(answer, dp[len][j]);

    return (answer >= n) ? -1 : answer;
}
