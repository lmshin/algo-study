#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> parent;

int find_parent(int x) {
	if (parent[x] == x) return x;

	//경로 압축, 바로 부모노드를 가리키도록 해 이후 find 연산 최적화
	return parent[x] = find_parent(parent[x]);
}

void union_set(int a, int b) {
	int rootA = find_parent(a);
	int rootB = find_parent(b);

	//다른 집합인 경우에만 실행
	if (rootA != rootB) {
		//대표자 선정 기준, 해당 집합에서 가장 작은 값
		if (rootA < rootB) {
			parent[rootB] = rootA;
		}
		else {
			parent[rootA] = rootB;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);

	//모든 원소는 자기 자신을 부모로 설정
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int opcode, a, b;
		cin >> opcode >> a >> b;

		//합치기
		if (opcode == 0) {
			union_set(a, b);
		}
		//확인하기
		else {
			if (find_parent(a) == find_parent(b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}

}
