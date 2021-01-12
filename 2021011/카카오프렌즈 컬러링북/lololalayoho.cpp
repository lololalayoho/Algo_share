#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int M, N;
int visit[101][101];
vector<vector<int>> map;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	visit[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = nx + dx[i];
			int nexty = ny + dy[i];
			if (nextx >= 0 && nextx < M && nexty >= 0 && nexty < N) {
				if (visit[nextx][nexty] == 0 && map[nextx][nexty] == map[x][y]) {
					visit[nextx][nexty] = 1;
					q.push(make_pair(nextx, nexty));
					cnt = cnt + 1;
				}
			}
		}
	}
	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	map = picture;
	M = m; N = n;
	int total_cnt = 0;
	int max_cnt = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (visit[i][j] == 0 && picture[i][j] != 0) {
				int value = bfs(i, j);
				if (value > max_cnt)
					max_cnt = value;
				total_cnt = total_cnt + 1;
			}
	answer[0] = total_cnt;
	answer[1] = max_cnt;
	return answer;
}