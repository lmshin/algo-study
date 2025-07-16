#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
int arr[200001] = { 0 };
unordered_map<int, int> countKind;

bool check() {
	int count = 0;
	for (int i = 1; i < 10; i++) {
		if (countKind[i] >= 1) { 
			count++;
		}

		if (count > 2) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	int start = 0;
	int end = 0;
	int length = 1;
	countKind[arr[end]]++;

	//51121

	while (end < n) {
		
		if (check()) { //종류가 2개이하라면 end++
			answer = max(answer, length);
			end++;
			countKind[arr[end]]++;
			length++;
		}
		else {//슬라이딩 윈도우 내에 종류가 2개 초과라면 start++
			countKind[arr[start]]--;
			start++;
			length--;
		}
	}


	cout << answer << endl;

	return 0;
}


//while(end < n) {
//	//end 증가
//	end++;
//
//	//start ~ end 까지 종류가 2개인지 확인
//	if (check[end] == 0) { //가지고있지 않은 과일이라면 종류가 늘어난 것
//		countKind++;
//		if (countKind > 2) {
//			/*check[start]--;
//			length--;*/
//			while (check[start] != 0) {
//				check[start]--;
//				length--;
//				if (check[start] == 0) {//다 다달았단는 
//					countKind--;
//					start++;
//				}
//				start++;
//
//			}
//			countKind--;
//		}
//		length++;
//		check[end]++;
//	}
//	else {
//		check[end]++;
//		length++;
//	}
//
//	answer = max(answer, length);
//}