#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n, r;
vector<int> v;
vector<int> path;

void solve(int depth) {
	if (depth == r) {
		for (int i = 0; i < r; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		path.push_back(v[i]);
		solve(depth + 1);
		path.pop_back();
	}
}

int main() {

	cin >> n >> r;

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	solve(0);
}