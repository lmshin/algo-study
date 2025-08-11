#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> dice(7);
	long long Min1 = 0x7fffffff;
	long long Max = 0;
	for (int i = 1; i <= 6; i++) {
		cin >> dice[i];
		Min1 = min(dice[i], Min1);
		Max = max(dice[i], Max);
	}

	long long Min2 = 0x7fffffff;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i == j) continue;
			if (i + j == 7) continue;
			//if (i == 1 && j == 6) continue;
			//if (i == 2 && j == 5) continue;
			//if (i == 3 && j == 4) continue;
			long long tmp = dice[i] + dice[j];
			Min2 = min(Min2, tmp);
		}
	}

	long long Min3 = 0x7fffffff;
	Min3 = min(Min3, dice[1] + dice[2] + dice[3]);
	Min3 = min(Min3, dice[1] + dice[2] + dice[4]);
	Min3 = min(Min3, dice[1] + dice[4] + dice[5]);
	Min3 = min(Min3, dice[1] + dice[3] + dice[5]);

	Min3 = min(Min3, dice[6] + dice[2] + dice[3]);
	Min3 = min(Min3, dice[6] + dice[2] + dice[4]);
	Min3 = min(Min3, dice[6] + dice[4] + dice[5]);
	Min3 = min(Min3, dice[6] + dice[3] + dice[5]);

	//cout << "Min1: " << Min1 << " Min2: " << Min2 << " Min3: " << Min3 << "\n";

	if (n == 1) cout << dice[1] + dice[2] + dice[3] + dice[4] + dice[5] + dice[6] - Max;
	else {
		long long answer = 0;
		answer += ((n - 2) * (n - 2) + (n - 2) * (n - 1) * 4) * Min1;
		//cout << "(n - 2) * (n - 2) : " << (n - 2) * (n - 2) << "  " << "(n - 2) * (n - 1) : " << (n - 2) * (n - 1) << "\n";
		answer += ((n - 1) * 4 + (n - 2) * 4) * Min2;
		answer += 4 * Min3;
		cout << answer;
	}
}