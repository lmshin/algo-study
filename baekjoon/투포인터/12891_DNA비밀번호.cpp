#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int A, C, G, T;
int answer = 0;

void checkACGT(unordered_map<char, int>& ACGT) {
	if (ACGT['A'] >= A && ACGT['C'] >= C && ACGT['G'] >= G && ACGT['T'] >= T) answer++;

	return;
}

int main() {
	int S, P;
	string s;
	cin >> S >> P;
	cin >> s;
	cin >> A >> C >> G >> T;

	int start = 0, end = P-1;
	unordered_map<char, int> ACGT = { 
		{'A',0},
		{'C',0},
		{'G',0},
		{'T',0},
	};
	
	for (int i = start; i <= end; i++) {
		ACGT[s[i]]++;
	}


	//idea, 슬라이딩 윈도우를 돌리면서 ACGT 숫자가 조건을 만족하는지 check!
	while (end < S) {
		checkACGT(ACGT);
		ACGT[s[start++]]--;
		ACGT[s[++end]]++;
	}

	cout << answer << '\n';

	return 0;
}