#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	
	string s;
	int k_min = 10;
	int k_max = -1;
	int k_size;

	cin >> s >> k_size;
	vector<int> k(k_size);

	for (int i = 0; i < k_size; i++) {
		cin >> k[i];
		if (k[i] < k_min) k_min = k[i];
		if (k[i] > k_max) k_max = k[i];
	}
	
	string answer;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] - '0' < k_min) { //ex) 19235 k = 4, 5
			for (int j = i; j < s.size() - 1; j++) {
				answer += (char)(k_max + '0');
			}
			break;
		}
		else if (s[i] - '0' > k_max) { //ex) 75346 k= 4,5
			for (int j = i; j < s.size(); j++) {
				answer += (char)(k_max + '0');
			}
			break;
		}
		//그게 아닌경우 ex) 45623, 5673 6731
		int tmp = -1;
		for (int j = 0; j < k_size; j++) {
			if (k[j] <= s[i] - '0') {
				tmp = max(tmp, k[j]);
			}
		}
		answer += (char)(tmp + '0');
	}		

	cout << answer;

	return 0;
}