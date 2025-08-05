#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int m, v;
    // 보석: 무게 기준 오름차순 정렬
    vector<pair<int, int>> jewels(n);
    for (int i = 0; i < n; i++) {
        cin >> jewels[i].first >> jewels[i].second;  // (무게, 가치)
    }
    sort(jewels.begin(), jewels.end()); // 무게 기준 오름차순

    // 가방: 무게 기준 오름차순
    vector<int> bags(k);
    for (int i = 0; i < k; i++) cin >> bags[i];
    sort(bags.begin(), bags.end());

    // 가치 높은 순으로 고르기 위한 max-heap
    priority_queue<int> pq;

    int j = 0;
    long long answer = 0;
    for (int i = 0; i < k; i++) {
        int bagWeight = bags[i];

        // 현재 가방 무게 이하의 보석들을 pq에 넣음
        while (j < n && jewels[j].first <= bagWeight) {
            pq.push(jewels[j].second);  // 가치만 push
            j++;
        }

        // 가치 가장 높은 보석 선택
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}