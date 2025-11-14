#include <string>
#include <vector>

using namespace std;


bool judge(vector<int> code, vector<vector<int>>& q, vector<int>& ans) {
    //일치하는 숫자가 맞는지 확인한다.
    int cnt;
    for (int i = 0; i < q.size(); i++) {
        cnt = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (code[j] == q[i][k]) cnt++;
            }
        }
        if (cnt != ans[i]) return false;
    }

    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    //모든 경우의 수 중에서 조건에 맞지 않는 것들은 pass?
    vector<int> code(5);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                for (int l = k + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        code[0] = i;
                        code[1] = j;
                        code[2] = k;
                        code[3] = l;
                        code[4] = m;

                        if (judge(code, q, ans)) answer++;
                    }
                }
            }
        }
    }


    return answer;
}