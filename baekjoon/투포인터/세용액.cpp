#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
ll a[5004];
ll ans[4];
//�� ���������� 10��¥�� ��� 3���� ������ 30���� �ִ�� ��� Ǯ� �ȴ�.
//���� Ǯ �� �̷� �κе��� ������ �Ѿ �� �ֵ��� int�� �ִ� 1e9, long long�� �ִ� 1e18�� �ΰ� �Ѿ��.
ll ret = 1e18;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n - 2; i++) {
		ll st = i + 1;
		ll en = n;
		while (st < en) {
			ll v = a[i] + a[st] + a[en];
			if (abs(v) < ret) { //�� ����� ������ �� ���밪�� ������ ���ߴ� �պ��� 0�� �� ������� Ȯ���Ѵ�.
				ret = abs(v); //ret�� ����!
				ans[1] = a[i];
				ans[2] = a[st];
				ans[3] = a[en];
			}
			if (v < 0) st++; //���� 0���� ���� ��� st�� ���������� �� ĭ �̵���Ų��.
			else en--; //���� 0���� ũ�ų� ���� ��� en�� �������� �� ĭ �̵���Ų��.
		}
	}
	cout << ans[1] << ' ' << ans[2] << ' ' << ans[3];
	return 0;
}