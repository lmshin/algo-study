#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int parent[200001];
int netSize[200001];

//�ش� ���Ұ� ���� ��Ʈ��ũ�� �θ��带 return �ϴ� �Լ�
//parent[b] = a;
//parent[c] = a;
int findParents(int a) {
	if (parent[a] == a) return a; // �̹� ��Ʈ�̸� return
	
	return parent[a] = findParents(parent[a]); // ��� ������ �ٷ� ��Ʈ�� parent[x]�� ����, �������� O(1) �� ã�´�.
}

//�� ��Ʈ��ũ�� �θ� ��尡 �ٸ��ٸ� ��ġ�� �Լ�
int unionFind(int a, int b) {

	int rootA = findParents(a);
	int rootB = findParents(b);

	//�ٸ� ��쿡 ��ģ��, �̹� ���ٸ� ���� ��Ʈ��ũ �̹Ƿ� �۾��� �� �ʿ䰡 ����
	if (rootA != rootB) {
		parent[rootB] = rootA;
		netSize[rootA] += netSize[rootB];
		
		//�������� netSize[b] �� �ʿ� ����
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