#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int calculate(vector<pair<int,char>>& buffer) {
	unsigned int answer = 0;
	int current_cnt, current_ch, next_cnt, next_ch;
	
	unordered_map<char, int> bracketMatch = {
		{'(',2},
		{'[',3}
	};

	int weight =1; //가중치
	stack<int> mul;

	for (int i = 0; i < buffer.size(); i++) {
	
		current_cnt = buffer[i].first;
		current_ch = buffer[i].second;
		
		if (i == buffer.size() - 1) {
			answer += weight * bracketMatch[current_ch];
			continue;
		}

		next_cnt = buffer[i+1].first;
		next_ch = buffer[i+1].second;

		if (current_cnt == next_cnt) {
			answer += weight * bracketMatch[current_ch];
			
		}
		else if (current_cnt < next_cnt) {
			weight *= bracketMatch[current_ch];
			mul.push(bracketMatch[current_ch]);
			continue;
		}
		else if (current_cnt > next_cnt) {
			//값 저장 후 tmp 감소
			//이전에 뭘 곱했는지에 대한 정보가 있어야 함, 번호가 바뀌었을 때의 숫자,
			answer += weight * bracketMatch[current_ch];
			int cnt_gap = current_cnt - next_cnt;
			for (int i = 0; i < cnt_gap; i++) {
				weight /= mul.top();
				mul.pop();
			}			
		}
	}

	return answer;
}

int main() {
	string s;
	stack<char> my_stack;
	cin >> s;


	int cnt = 0;
	vector<pair<int, char>> buffer;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
			buffer.push_back(make_pair(cnt, s[i]));
			my_stack.push(s[i]);
		}
		else if (s[i] == '[') {
			cnt++;
			buffer.push_back(make_pair(cnt, s[i]));
			my_stack.push(s[i]);
		}
		else if (my_stack.empty()) {
			cout << "0";
			return 0;
		}
		else { 

			if (my_stack.top() == '(' && s[i] == ')') {
				my_stack.pop();
				cnt--; 
			}
			else if (my_stack.top() == '[' && s[i] == ']') {
				my_stack.pop();
				cnt--;
			}
		}
	}

	if (my_stack.size() == 0) {
		cout << calculate(buffer);
	}
	else {
		
		cout << "0";
	}

	return 0;
}