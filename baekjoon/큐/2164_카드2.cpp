#include<iostream>
#include<deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 1; i <= n; i++) {
        dq[i-1] = i;
    }
    while (dq.size() > 1) {
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    cout << dq.front() << "\n";

    return 0;
}