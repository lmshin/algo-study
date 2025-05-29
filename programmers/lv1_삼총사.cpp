#include <string>
#include <vector>

using namespace std;

int count = 0;

void countConbination(int start, int depth, int sum, const vector<int>& vec) {
    if (depth == 3) {
        if (sum == 0) count++;
        return;
    }

    for (int i = start; i < vec.size(); ++i) {
        countConbination(i + 1, depth + 1, sum + vec[i], vec);
    }
}

int solution(vector<int> number) {
    count = 0; // 전역 변수 초기화
    countConbination(0, 0, 0, number);
    return count;
}
