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

	//������� ����
	cin >> input;
	pivot = input;
	cout << pivot << "\n";

	for (int i = 1; i < n; i++) {
		cin >> input;
		if (input < pivot) {
			//����ť�� push
			left_pq.push(input);
			//���� queue size�� �����ʺ��� ũ�ٸ� pivot�� �����ʿ� push �ϰ� ����ť�� top �� pivot����
			if (left_pq.size() > right_pq.size()) {
				right_pq.push(pivot);
				pivot = left_pq.top();
				left_pq.pop();
			}
		}
		else {// ���ų� ũ�ٸ� ������ queue�� �ִ´�
			right_pq.push(input);//������ queue�� ���� ���� ũ�ٸ�  pivot�� ���������� �ű��.

			if (left_pq.size() + 1 < right_pq.size()) {
				left_pq.push(pivot);
				pivot = right_pq.top();
				right_pq.pop();
			}
		}

		cout << pivot << "\n";
	}
}