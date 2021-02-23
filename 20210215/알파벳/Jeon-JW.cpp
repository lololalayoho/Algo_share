//https://www.acmicpc.net/problem/1987
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int R, C;
int map[21][21];
bool visit[27]; // 1~27
int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};
int answer = 0;

void dfs(int row, int col, int cnt) {
	cnt++;
	visit[map[row][col]] = 1;
	//cout << row << col << endl;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		ny = row + dir[0][i];
		nx = col + dir[1][i];

		if (nx < 1 || ny > R) continue;
		if (ny < 1 || nx > C) continue;
		if (visit[map[ny][nx]]) continue;
		
		dfs(ny, nx, cnt);
	}

	visit[map[row][col]] = 0;
	if (answer < cnt) answer = cnt;
}

//65~90
int main() {

	cin >> R >> C;
	char temp;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> temp;
			map[i][j] = (int)temp - 64;
		}
	}

	dfs(1, 1, 0);

	cout << answer << endl;

	return 0;
}