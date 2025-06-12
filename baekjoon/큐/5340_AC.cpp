#include<iostream>
#include<deque>
#include<string>
using namespace std;

//이 로직을 좀 더 간단하게 짤 수 있을지 궁금
void fill_queue(deque<int>& q, string arr) {
	for (int i = 0; i < arr.size(); i++) {
		if ('0' <= arr[i] && arr[i] <= '9') {
			//숫자라면? 숫자가 아닌게 나올때까지 추가
			string tmp;
			tmp += arr[i++];
			while ('0' <= arr[i] && arr[i] <= '9') {
				tmp += arr[i];
				i++;
			}
			i--;
			q.push_back(stoi(tmp));
		}
	}
}

void print_vector(deque<int>& q, bool isReversed) {
	
	
	if (q.size() == 0) {
		cout << "[]" << "\n";
	}
	else if(!isReversed){
		
		cout << "[" << q.front();
		for (int i = 1; i < q.size(); i++) {
			cout << "," << q[i];
		}
		cout << "]" << "\n";
	}
	else {
		cout << "[" << q.back();
		for (int i = q.size() - 2; i >= 0; i--) {
			cout << "," << q[i];
		}
		cout << "]" << "\n";
	}
	
}

void funcR(deque<int>& q) {
	int tmp;
	int size = q.size();
	for (int i = 0; i < size / 2; i++) {
		tmp = q[i];
		q[i] = q[size - 1 - i];
		q[size - 1 - i] = tmp;
	}
}

void funcD(deque<int>& q, bool isReversed) {
	if (isReversed) {
		q.pop_back();
	}
	else {
		q.pop_front();
	}
}

void excute_command(deque<int>& q, string command) {
	bool isReversed = false;
	for (char ch : command) {
		if (ch == 'R') {
			isReversed = !isReversed;
		}
		else if(ch == 'D' && q.size()>0) {
			funcD(q,isReversed);
		}
		else if (ch == 'D' && q.size() == 0) {
			cout << "error" << "\n";
			return;
		}
	}

	print_vector(q, isReversed);
}

int main() {
	int T;
	cin >> T;
	string command,arr;
	deque<int> q;
	int size;

	//R이 뒤집기, D가 빼기
	for (int i = 0; i < T; i++) {
		cin >> command >> size >> arr;
		deque<int> q;
		fill_queue(q,arr);
		excute_command(q,command);

	}

	return 0;
}