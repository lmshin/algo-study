#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int num = 666;
	int count = 0;
	while (1) {
		if (to_string(num).find("666") != string::npos) {
			count++;
		}

		if (count == n) {
			cout << num << "\n";
			break;
		}

		num++;
	}

	return 0;
}