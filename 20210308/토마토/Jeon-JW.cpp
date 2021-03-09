//https://www.acmicpc.net/problem/7576
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
// bfs

using namespace std;

int N, M;
int map[1001][1001];
int answer;

queue<pair<int, int>> q;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

// 하나라도 익힐경우 1 못익히면 0
void solution() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[0][i];
			int nc = c + dir[1][i];

			if (nr<1 || nr > N || nc<1 || nc >M) continue;
			if (map[nr][nc] != 0) continue;

			map[nr][nc] = map[r][c] + 1;
			q.push(make_pair(nr, nc));
		}
	}
}


int main() {

	cin >> M >> N; // 세로, 가로

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	
	solution();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				cout << "-1" << endl;
				return 0;
			}
			if (answer < map[i][j]) {
				answer = map[i][j];
			}
		}
	}

	cout << answer - 1 << endl;

	return 0;
}