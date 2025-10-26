#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;

//해당 
int findparent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findparent(parent[x]);
}

void Union(int a, int b) {
	int rootA = findparent(a);
	int rootB = findparent(b);

	if (rootA > rootB) {
		parent[rootA] = rootB;
	}
	else if(rootA < rootB) {
		parent[rootB] = rootA;
	}
}

int main() {
	int g, p, g_i;
	int answer = 0;

	cin >> g >> p;
	parent.resize(g + 1);
	for (int i = 0; i <= g; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < p; i++) {
		cin >> g_i;
		// 1. 도킹할 수 있는 가장 큰 게이트 R을 찾는다.
		int R = findparent(g_i);

		// 2. R이 0보다 크면 도킹 가능하다.
		if (R > 0) {
			// 도킹 성공!
			// 3. R번 게이트에 도킹했으므로, R번 게이트는 이제 R-1 게이트로 연결한다.
			//    (다음에 R에 접근하는 비행기는 자동으로 R-1의 대표자를 찾게 됨)
			answer++;
			Union(R, R - 1);

			// 도킹 횟수 증가
		}
		else {
			// R == 0, 1번까지 모두 찼으므로 도킹 불가능.
			// 공항 폐쇄 (반복문 종료)
			break;
		}
	}

	cout << answer;

}