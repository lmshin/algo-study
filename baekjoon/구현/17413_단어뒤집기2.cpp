#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string get_reverse_string(string s) {
	string reverse_string;

	for (int i = 0; i < s.size(); i++) {
		string tmp;
		if (s[i] == '<') {
			reverse_string += s[i];
			while (s[++i]!='>') {
				reverse_string += s[i];
			}
			reverse_string += s[i];
		}
		else if (s[i] == ' ') {
			reverse_string += s[i];
		}
		else {//단어를 찾은 경우
			while (s[i] != ' ' && s[i] != '<' && i < s.size()) {
				tmp += s[i];
				i++;
			}
			reverse(tmp.begin(), tmp.end());
			reverse_string += tmp;
			i--;
		}
	}

	return reverse_string;
}

string reverse_process(const string& s) {
	string result, word;
	bool in_tag = false;

	for (ch char : s) {
		if (ch == '<') {
			reverse(word.begin, word.end());
			result += word;
			word.clear();

			in_tag = true;
			result += ch;
		}
		else if (ch == '>') {
			in_tag = false;
			result += ch;
		}
		else if (in_tag) {
			result += ch;
		}
		else {
			if (ch == ' ') {
				reverse(word.begin, word.end());
				result += word;
				word.clear();
			}
			else {
				word += ch;
			}
		}
	}

	if (!word.empty()) {
		reverse(word.begin, word.end());
		result += word;
	}

	return result;
}

int main() {
	string s;
	getline(cin, s);
	
	string answer = get_reverse_string(s);
	cout << answer;

	return 0;

}