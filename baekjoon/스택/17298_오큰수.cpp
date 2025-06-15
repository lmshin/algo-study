#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int n, num;
	stack<pair<int, int>> s;
	
	cin >> n;
	vector<int> v(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> num;
		while (!s.empty() && s.top().second < num) {
			v[s.top().first] = num;
			s.pop();
		}
		s.push(make_pair(i, num)); 
	}
	
	while (!s.empty()) {
		v[s.top().first] = -1;
		s.pop();
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i] << " ";
	}

	return 0;
}

//int main() {
//	int n, num;
//	stack<pair<int, int>> s;
//	
//	cin >> n;
//	vector<int> v(n + 1);
//
//	//처음에 넣고 시작
//	cin >> num;
//	s.push(make_pair(1, num));
//	
//	for (int i = 2; i <= n; i++) {
//		cin >> num;
//		if(s.empty()) {
//			s.push(make_pair(i,num));
//		}
//		else if (s.top().second >= num) {
//			s.push(make_pair(i, num));
//		}
//		else {
//			while (!s.empty() && s.top().second < num) {
//				v[s.top().first] = num;
//				s.pop();
//			}
//			s.push(make_pair(i, num));
//		}
//	}
//
//	while (!s.empty()) {
//		v[s.top().first] = -1;
//		s.pop();
//	}
//
//	for (int i = 1; i <= n; i++) {
//		cout << v[i] << " ";
//	}
//
//	return 0;
//}