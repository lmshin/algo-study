#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<string> v;
		for (int j = 0; j < n; j++) {
			string tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		bool flag = true;
		for (int j = 0; j < n - 1; j++) {
			if (v[j].size() <= v[j + 1].size()) {
				if (!v[j].compare(v[j + 1].substr(0, v[j].size()))) {
					//cout << "compare1 : " << v[j] << " / " << v[j + 1].substr(0, v[j].size()) << "\n";
					flag = false;
					break;
				}
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}