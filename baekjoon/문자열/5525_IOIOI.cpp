#include<iostream>
#include<string>
using namespace std;

//2�� for �� ���� �ٷ� �ð����⵵���� �ɸ���
int main() {
	int n, s_size;
	int answer = 0;
	string s;
	cin >> n >> s_size >> s;

	int i = 0;
	int count = 0;
	while (i < s_size - 2) {
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			count++;
			i += 2; // "IOI" �ϳ��� �� ���ھ� �ǳʶ�

			// Pn ���� �ϼ� �� ���� �߰�
			if (count == n) {
				answer++;
				count--; // ��ġ�� ���� ���
			}
		}
		else {
			i++;
			count = 0; // ������: �ٽ� ����
		}
	}

	cout << answer << "\n";

	return 0;
}