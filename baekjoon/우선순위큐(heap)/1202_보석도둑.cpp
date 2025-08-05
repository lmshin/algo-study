#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int m, v;
    // ����: ���� ���� �������� ����
    vector<pair<int, int>> jewels(n);
    for (int i = 0; i < n; i++) {
        cin >> jewels[i].first >> jewels[i].second;  // (����, ��ġ)
    }
    sort(jewels.begin(), jewels.end()); // ���� ���� ��������

    // ����: ���� ���� ��������
    vector<int> bags(k);
    for (int i = 0; i < k; i++) cin >> bags[i];
    sort(bags.begin(), bags.end());

    // ��ġ ���� ������ ���� ���� max-heap
    priority_queue<int> pq;

    int j = 0;
    long long answer = 0;
    for (int i = 0; i < k; i++) {
        int bagWeight = bags[i];

        // ���� ���� ���� ������ �������� pq�� ����
        while (j < n && jewels[j].first <= bagWeight) {
            pq.push(jewels[j].second);  // ��ġ�� push
            j++;
        }

        // ��ġ ���� ���� ���� ����
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}