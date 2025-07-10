#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;

	//잘못된 암호
	if (s[0] == '0') {
		cout << "0" << "\n";
		return 0;
	}
	

	vector<long long> dp(s.size()+1, 1);
	for (int i = s.size()-2; i >= 0; i--) {
		int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
		if (1 <= tmp && tmp <= 26) {
			
			dp[i] = (dp[i + 1] + dp[i + 2]) % 1000000;
		}
		else {
			if (tmp % 10 == 0) {
				cout << "0" << "\n";
				return 0;
			}
			dp[i] = dp[i + 1] % 1000000;
		}
	}

	cout << dp[0] % 1000000;
}

int main() {
    string s;
    cin >> s;

    if (s[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(s.size() + 1, 0);

    dp[s.size()] = 1;

    if (s[s.size() - 1] == '0') {
        dp[s.size() - 1] = 0;
    }
    else {
        dp[s.size() - 1] = 1;
    }

    for (int i = s.size() - 2; i >= 0; i--) {

        if (s[i] == '0') {
            dp[i] = 0;
            continue;
        }

        dp[i] = dp[i + 1] % MOD;

        int combined = (s[i] - '0') * 10 + (s[i + 1] - '0');

        if (combined >= 10 && combined <= 26) {

            dp[i] = (dp[i] + dp[i + 2]) % MOD;
        }

    }

    return 0;
}