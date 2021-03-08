// https://www.acmicpc.net/problem/2178
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int map[101][101];
bool visited[101][101];
int cnt[101][101];
queue<pair<int, int>> que;
int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};

void solution(int row, int col) {
	visited[row][col] = true;
	cnt[row][col]++;
	que.push(make_pair(row, col));
	pair<int, int> cur;
	int nr, nc;
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			nr = cur.first + dir[0][i];
			nc = cur.second + dir[1][i];
			
			if (nr< 1 || nr>N || nc<1 || nc>M) continue;
			if (visited[nr][nc]) continue;
			if (!map[nr][nc])continue;

			visited[nr][nc] = true;
			que.push(make_pair(nr, nc));
			cnt[nr][nc] = cnt[cur.first][cur.second] + 1;
		}
	}
	return;
}

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	solution(1,1);

	cout << cnt[N][M] << endl;
	return 0;
}