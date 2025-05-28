#include <string>
#include <vector>

using namespace std;
int answer = 0;

void exchangeBottles(int a, int b, int n) {
    if (n < a) return;

    int exchanged = (n / a) * b;
    answer += exchanged;
    int remaining = exchanged + n % a;

    exchangeBottles(a, b, remaining);
}

int solution(int a, int b, int n) {

    exchangeBottles(a, b, n);

    return answer;
}