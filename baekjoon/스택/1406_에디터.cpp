#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
int n;

int main() {
	stack<char> my_stack;
	stack<char> buffer;

	string s;
	
	int n;
	cin >> s >> n;
	for (int i = 0; i < s.size(); i++) {
		my_stack.push(s[i]);
	}



	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;

		if (c == 'L') {
			if (!my_stack.empty()) {
				int tmp = my_stack.top();
				buffer.push(tmp);
				my_stack.pop();
			}
		}
		else if (c == 'D') {
			if (buffer.size() > 0) {
				my_stack.push(buffer.top());
				buffer.pop();
			}
		}
		else if (c == 'B') {
			if (!my_stack.empty()) my_stack.pop();
		}
		else if (c == 'P') {
			char ch;
			cin >> ch;
			my_stack.push(ch);
		}
	}

	while (!my_stack.empty()) {
		buffer.push(my_stack.top());
		my_stack.pop();
	}

	while (!buffer.empty()) {
		cout << buffer.top();
		buffer.pop();
	}
	cout << "\n";

	return 0;
}