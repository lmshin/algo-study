#include<iostream>
#include<vector>
#include<queue> 
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int left_size = 0, right_size = 0, pivot;
	int n, input;
	cin >> n;
	
	priority_queue<int> left_pq;
	priority_queue<int, vector<int>, greater<int>> right_pq;

	//기준잡고 시작
	cin >> input;
	pivot = input;
	cout << pivot << "\n";

	for (int i = 1; i < n; i++) {
		cin >> input;
		if (input < pivot) {
			//왼쪽큐에 push
			left_pq.push(input);
			//왼쪽 queue size가 오른쪽보다 크다면 pivot을 오른쪽에 push 하고 왼쪽큐의 top 을 pivot으로
			if (left_pq.size() > right_pq.size()) {
				right_pq.push(pivot);
				pivot = left_pq.top();
				left_pq.pop();
			}
		}
		else {// 같거나 크다면 오른쪽 queue에 넣는다
			right_pq.push(input);//오른쪽 queue가 왼쪽 보다 크다면  pivot을 오른쪽으로 옮긴다.

			if (left_pq.size() + 1 < right_pq.size()) {
				left_pq.push(pivot);
				pivot = right_pq.top();
				right_pq.pop();
			}
		}

		cout << pivot << "\n";
	}
}