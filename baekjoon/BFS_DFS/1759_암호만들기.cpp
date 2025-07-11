#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int l, c;
vector<string> ch;

bool check(string password) {
	//자음 모음 개수 체크
	int a = 0, b = 0;
	for (int i = 0; i < l; i++) {
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
			a++;
		}
		else {
			b++;
		}
	}

	if (a >= 1 && b >= 2) return true;
	return false;
}

void solve(int idx,int depth, string password) {
	if (depth == l) {
		if (check(password)) {
			cout << password << "\n";
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		solve(i + 1, depth + 1, password + ch[i]);
	}
}

int main() {

	cin >> l >> c;
	
	string input;
	for (int i = 0; i < c; i++) {
		cin >> input;
		ch.push_back(input);
	}

	sort(ch.begin(), ch.end());

	solve(0,0,"");
}