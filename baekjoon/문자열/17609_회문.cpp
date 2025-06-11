#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s, int front, int back) {//ȸ������ �Ǵ�
	while (front < back) {
		if (s[front] != s[back]) {
			return false;
		}
		front++;
		back--;
	}
	return true;
}

bool isPseudoPalindrome(string s) {//����ȸ������ �Ǵ�

	int front = 0;
	int back = s.size() - 1;

	while (front < back) {
		if (s[front] != s[back]) {

			
			if (isPalindrome(s,front+1,back)) { //�� ����
				return true;
			}
			else if (isPalindrome(s,front, back-1)) { //�� ����
				return true;
			}
			else {
				return false;
			}
		}
		front++;
		back--;
	}

	cout << "1" << "\n";
	return true;
}

int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int s_size = s.size();
		if (isPalindrome(s, 0, s_size - 1)) {
			cout << "0" << "\n";
		}
		else if (isPseudoPalindrome(s)) {
			cout << "1" << "\n";
		}
		else {
			cout << "2" << "\n";
		}
	}

	return 0;
}