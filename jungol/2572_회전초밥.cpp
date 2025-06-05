#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); // C�� C++ ��Ʈ�� ����ȭ ��Ȱ��ȭ
	cin.tie(nullptr);

	int N, d, k, c, chobab;
	vector<int> line;
	line.reserve(30001);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> chobab;
		line.push_back(chobab);
	}

	//�ִ밪 ���
	int kind, Max = -1;
	set<int> s;
	//ȸ���ϴ� ��쵵 ����ؾ��Ѵ�.
	for (int i = 0; i < N; i++) {

		kind = 0;

		for (int j = i; j < i + k; j++) {
			//index�� �Ѿ�°��
			if (j >= N) {
				s.insert(line[j - N]);
			}
			else {
				s.insert(line[j]);
			}
		}
		kind = s.size();

		if (s.find(c) == s.end()) {
			kind++;
		}

		Max = max(Max, kind);
		s.clear();
	}

	cout << Max << endl;

	return 0;
}