#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	//3, 5 로 만들 수 있는 최소한의 봉지의 수를 구하는 문제,
	vector<int> dp(n + 1, 0); //궁금해서 찾아봄, int * 5000 을 vector로 할당하면 얼마만큼의 메모리를 잡아먹지? 20KB, 문제조건은 128MB, 시간제한 1초
	dp[3] = 1;				 //동적할당으로 하면 메모리를 좀 더 적게쓴다, push_back으로 사용하면 그때마다 맨뒤에 메모리를 할당한다, 메모리는 적게쓰겠지만 연산량은 훨씬 많아진다.
	dp[4] = -1;				 //push_back의 연산량은 capacitor 가 가득 찰때마다 배열 전체를 옮겨야 하기 때문에 연산량이 훨씬 많아진다.
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = -1;
	dp[8] = 2;
	dp[9] = 3;
	dp[10] = 2;
	dp[11] = 3;
	dp[12] = 4; //여기서 부터 점화식이 적용된다.
	for (int i = 13; i <= n; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	cout << dp[n] << '\n';
	checkCapacityOfVector();

	return 0;
}

void checkCapacityOfVector() {
	std::vector<int> v;
	for (int i = 0; i < 1000; ++i) {
		v.push_back(i);
		std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << "\n";
	}
}