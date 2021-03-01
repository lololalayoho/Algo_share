#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct position {
	int x;
	int y;
	int value;
};
int N, M, answer;
int map[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs(int startx, int starty) {
	int visit[21][21] = { 0 };
	int cnt = 0;
	visit[startx][starty] = 1;
	queue<position> q; position p; p.x = startx; p.y = starty; p.value = 1;
	q.push(p);
	for (int k = 1; k <= N + 1; k++) {
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int value = q.front().value;
			if (value > k)
				break;
			if (map[x][y] == 1)
				cnt = cnt + 1;
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N) {
					if (visit[x + dx[i]][y + dy[i]] == 0) {
						visit[x + dx[i]][y + dy[i]] = 1;
						position p; p.x = x + dx[i]; p.y = y + dy[i]; p.value = value + 1;
						q.push(p);
					}
				}
			}
		}
		int cost = (cnt * M) - ((k*k) + (k - 1)*(k - 1));
		if (cost >= 0)
			if (cnt > answer)
				answer = cnt;
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> N >> M;
		//init
		vector<position> home;
		answer = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				bfs(i, j);
		cout << "#" << t << " " << answer << endl;
	}
}