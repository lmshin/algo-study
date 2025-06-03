#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	
	vector<vector<char>> map(m, vector<char>(n));
	string s;

	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}
	int result = 99999999;

	for (int i = 0; i <= m-8; i++) {
		for (int j = 0; j <= n-8; j++) {
			int w_start = 0;
			int b_start = 0;

			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					char current = map[k + i][l + j];

					if ((k + l) % 2 == 0) {
						if (current != 'B') b_start++;
						if (current != 'W') w_start++;
					}
					else {
						if (current != 'W') b_start++;
						if (current != 'B') w_start++;
					}
					
				}
			}

			result = min(result, min(b_start, w_start));
		}
	}


	cout << result << '\n';

	return 0;
}