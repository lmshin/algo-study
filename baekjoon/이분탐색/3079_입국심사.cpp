#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int n, m, t;
long long answer = LLONG_MAX;;
vector<long long> times;

bool check(long long time) {
	//�־��� time �� �� �ɻ��� ���� ���
	//4.5 ���� �ִٸ�? 20�� �̶��?, �ִ� 100��
	long long sum = 0;
	//50�ʷ� Ȯ��
	for (int i = 0; i < n; i++) {
		sum += time / times[i];
		if (sum >= m) return true;
	}

	return false;
}

int main() {
	cin >> n >> m;
	times.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}

	//�ɻ縦 �޴µ� �ɸ��� �ּҰ��� �̺�Ž������ ���ϰ� Ȯ���Ѵ�.
	long long start, end, mid;
	start = 1;
	end = *max_element(times.begin(), times.end()) * m;

	while (start <= end) {
		mid = (start + end) / 2;

		if (check(mid)) { //�����ϸ� �� �ٿ�����.
			end = mid - 1;
			answer = mid;
		}
		else {
			start = mid + 1;
		}

	}

	cout << answer;
}