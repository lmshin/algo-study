#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long a, b;
    for (int i = 0; i <= d; i += k) {
        a = i;
        b = floor(sqrt((long long)pow(d, 2) - (long long)pow(a, 2)));
        answer += b / k + 1;
    }

    return answer;
}