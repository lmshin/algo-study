#include<iostream>
#include<vector>
#include<string>
using namespace std;
int arr[1000];

struct myType {
	vector<int> digits;
	int strike;
	int ball;
};

vector<myType> hint;


bool judge(string tmp, myType hint) {
	vector<int> digits(3);
	digits[0] = tmp[0] - '0';
	digits[1] = tmp[1] - '0';
	digits[2] = tmp[2] - '0';

	int strike = 0, ball = 0; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j && digits[i] == hint.digits[j]) strike++;
			else if (i != j && digits[i] == hint.digits[j]) ball++;
		}
	}

	return (strike == hint.strike && ball == hint.ball);
}

int main() {
	int n, number, strike, ball;
	int answer = 0;
	cin >> n;
	
	vector<int> tmp(3, 0);
	for (int i = 0; i < n; i++) {
		cin >> number >> strike >> ball;
		tmp[0] = number / 100;
		tmp[1] = (number % 100) / 10;
		tmp[2] = (number % 10);
		hint.push_back({ tmp,strike,ball });
	}

	for (int i = 123; i < 999; i++) {
		string tmp = to_string(i);
		//각 자릿수가 같은게 존재하는 경우, 0이 포함된 경우 continue;
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) continue;
		if (tmp[1] == 0 || tmp[2] == 0) continue;

		//나머지 경우에 대해서 hint 의 모든 조건을 만족하면 answer++;
		bool istrue = true;
		for (int j = 0; j < hint.size(); j++) {
			if (!judge(tmp, hint[j])) {
				istrue = false;
				break;
			}
		}

		if (istrue) answer++;
	}

	cout << answer;

}