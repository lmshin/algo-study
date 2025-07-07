#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	priority_queue < pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	long long input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		if (input > 0) {
			pq.push(make_pair(input, 1));
		}
		else if(input < 0){
			pq.push(make_pair(abs(input), -1));
		}
		else {
			if (pq.empty()) {
				cout << "0" << "\n";
				continue;
			}
			
			if (pq.top().second > 0) {
				cout << pq.top().first << "\n";
			}
			else {
				cout << pq.top().first * -1 << "\n";
			}

			pq.pop();
		}
		

	}
	
}