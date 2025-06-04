#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n, x, y;
	vector<vector<int>> map(100, vector<int>(100,0));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				map[j][k] = 1;
			}
		}
	}

	//둘래길이 구하기
	int nx, ny, result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					nx = i + dx[k];
					ny = j + dy[k];

					if (nx<0||nx>=100||ny<0||ny>=100) {
						result++;
					}
					else if (!map[nx][ny]) {
						result++;
					}
				}
				
			}
		}
	}

	cout << result << "\n";
	return 0;
}