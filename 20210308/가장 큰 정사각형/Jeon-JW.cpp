//https://www.acmicpc.net/problem/1915
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int map[1001][1001];
int answer = 0;


int main(){

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1]))+1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)  {
			if (answer < map[i][j]) {
				answer = map[i][j];
			}
		}
	}

	cout << answer * answer << endl;


	return 0;

}