#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int parent[200001];
int netSize[200001];

//해당 원소가 속한 네트워크의 부모노드를 return 하는 함수
//parent[b] = a;
//parent[c] = a;
int findParents(int a) {
	if (parent[a] == a) return a; // 이미 루트이면 return
	
	return parent[a] = findParents(parent[a]); // 재귀 끝나면 바로 루트를 parent[x]에 저장, 다음에는 O(1) 로 찾는다.
}

//두 네트워크의 부모 노드가 다르다면 합치는 함수
int unionFind(int a, int b) {

	int rootA = findParents(a);
	int rootB = findParents(b);

	//다른 경우에 합친다, 이미 같다면 같은 네트워크 이므로 작업을 할 필요가 없음
	if (rootA != rootB) {
		parent[rootB] = rootA;
		netSize[rootA] += netSize[rootB];
		
		//이제부터 netSize[b] 는 필요 없다
	}
	
	return netSize[rootA];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int f;
		cin >> f;
		unordered_map<string, int> nameToId;
		int nextId = 1;

		for (int i = 0; i < 2 * f; i++) {
			parent[i] = i;
			netSize[i] = 1;
		}

		while (f--) {
			string a, b;
			cin >> a >> b;

			if (!nameToId.count(a)) nameToId[a] = nextId++;
			if (!nameToId.count(b)) nameToId[b] = nextId++;

			int idA = nameToId[a];
			int idB = nameToId[b];

			cout << unionFind(idA, idB) << "\n";
		}
		
	} 
}