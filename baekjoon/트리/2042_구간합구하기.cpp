#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long arr[1000010];
long long tree[4000011];

//leaf node ���� root node  ���� ��������� node�� ä��������.
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start]; //leaf ���� ��
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2 , start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	int a, b;
	long long c;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {//b�� �� c�� ����
			long long tmp = c - arr[b];
			arr[b] = c;
			update(1, 1, n, b, tmp);
		}
		else {
			//b~c ������ ��
			cout << query(1, 1, n, b, c) << "\n";
		}
	}

}