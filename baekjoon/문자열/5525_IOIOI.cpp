#include<iostream>
#include<string>
using namespace std;

//2중 for 문 들어가면 바로 시간복잡도에서 걸릴듯
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
			i += 2; // "IOI" 하나는 두 문자씩 건너뜀

			// Pn 패턴 완성 시 정답 추가
			if (count == n) {
				answer++;
				count--; // 겹치는 패턴 고려
			}
		}
		else {
			i++;
			count = 0; // 끊어짐: 다시 시작
		}
	}

	cout << answer << "\n";

	return 0;
}