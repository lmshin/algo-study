#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int F, S, G, U, D;
int main() {
	cin >> F >> S >> G >> U >> D;
	queue<pair<int,int>> q;
	vector<bool> visited(1000001, 0);
	
	q.push(make_pair(S, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == G) {
			cout << cnt << "\n";
			return 0;
		}

		if (cur + U <= F && !visited[cur + U]) {
			q.push(make_pair(cur + U, cnt + 1));
			visited[cur + U] = true;
		}

		if (cur - D > 0 && !visited[cur - D]) {
			q.push(make_pair(cur - D, cnt + 1));
			visited[cur - D] = true;
		}
	}

	cout << "use the stairs";
}