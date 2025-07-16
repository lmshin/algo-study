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
		
		if (check()) { //������ 2�����϶�� end++
			answer = max(answer, length);
			end++;
			countKind[arr[end]]++;
			length++;
		}
		else {//�����̵� ������ ���� ������ 2�� �ʰ���� start++
			countKind[arr[start]]--;
			start++;
			length--;
		}
	}


	cout << answer << endl;

	return 0;
}


//while(end < n) {
//	//end ����
//	end++;
//
//	//start ~ end ���� ������ 2������ Ȯ��
//	if (check[end] == 0) { //���������� ���� �����̶�� ������ �þ ��
//		countKind++;
//		if (countKind > 2) {
//			/*check[start]--;
//			length--;*/
//			while (check[start] != 0) {
//				check[start]--;
//				length--;
//				if (check[start] == 0) {//�� �ٴ޾Ҵܴ� 
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