#include<iostream>
#include<deque>
#include<queue>
#include<string>
using namespace std;

//version1
void UsingDeque() {
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 1; i <= n; i++) {
        dq[i - 1] = i;
    }
    while (dq.size() > 1) {
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    cout << dq.front() << "\n";
}

//version1
void UsingQueue() {
    int n;
    cin >> n;
    queue<int> q(n);
    for (int i = 1; i <= n; i++) {
        q[i - 1] = i;
    }
    while (q.size() > 1) {
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << dq.front() << "\n";
}

//version1
void UsingString() {
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        s += (i+1) + '0';
    }

    while (s.size() > 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                string tmp = "";
                tmp += s[i];
                s = tmp;
            }
        }
    }
    cout << s << "\n";
}

//version3
int main() {
    UsingString();
    return 0;
}


