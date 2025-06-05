#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); // C와 C++ 스트림 동기화 비활성화
	cin.tie(nullptr);

	int N, d, k, c, chobab;
	vector<int> line;
	line.reserve(30001);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> chobab;
		line.push_back(chobab);
	}

	//최대값 계산
	int kind, Max = -1;
	set<int> s;
	//회전하는 경우도 고려해야한다.
	for (int i = 0; i < N; i++) {

		kind = 0;

		for (int j = i; j < i + k; j++) {
			//index가 넘어가는경우
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