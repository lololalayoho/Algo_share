//https://www.acmicpc.net/problem/2210
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};
char map[5][5];
unordered_map<string, int> m;
int result = 0;

void dfs(int row, int col, int cnt, string answer) {
	if (answer.length() == 6) {
		m[answer]++;
		//cout << answer << endl;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nr = row + dir[0][i];
		int nc = col + dir[1][i];

		if (nr < 0 || nr > 4 || nc < 0 || nc > 4) continue;
		
		dfs(nr, nc, cnt + 1, answer + map[row][col]);
	}

}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, "");
		}
	}

	
	for (auto item : m) {
		//cout << item.first << " " << item.second << endl;
		result++;
	}

	cout << result << endl;

	return 0;
}