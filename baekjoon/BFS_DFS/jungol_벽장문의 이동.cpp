#include<iostream>
#include<vector>
using namespace std;


void dfs(int point1, int point2, vector<int>& door, int depth, int cost, int& answer) {

	if (cost >= answer) return;

	if (depth == door.size()) {//종료
		answer = min(answer, cost);
		return;
	}
	 
	int target = door[depth];
	
	//dfs(target, point2, door, depth + 1, cost + abs(target - point1), answer); //left 가 변하는 경우
	//dfs(point1, target, door, depth + 1, cost + abs(target - point2), answer); //right가 변하는 경우

	if (point1 < target && target < point2) {
		dfs(target, point2, door, depth + 1, cost + abs(target - point1), answer); //left 가 변하는 경우
		dfs(point1, target, door, depth + 1, cost + abs(target - point2), answer); //right가 변하는 경우
	}
	else if (point1 >= target) {
		dfs(target, point2, door, depth + 1, cost + abs(target - point1), answer); //left 가 변하는 경우
	}
	else{
		dfs(point1, target, door, depth + 1, cost + abs(target - point2), answer); //right가 변하는 경우
	}

	//else if (point1 == target) {
	//	dfs(point1, point2, door, depth + 1, cost, answer);
	//}
	//else if (point2 == target) {
	//	dfs(point1, point2, door, depth + 1, cost, answer);
	//}
}

int main() {
	int n;
	cin >> n;
	int point1, point2;
	cin >> point1 >> point2;

	int use;
	cin >> use;
	
	int num;
	vector<int> door;
	for (int i = 0; i < use; i++) {
		cin >> num;
		door.push_back(num);
	}

	int answer = 0x7FFFFFFF;
	int depth = 0;
	dfs(point1, point2, door, 0, 0, answer);

	cout << answer << "\n";

	return 0;
}