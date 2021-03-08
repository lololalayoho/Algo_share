#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int v[101][101];
int visit[101][101];
int N, M;

void bfs() {
	visit[0][0] = 1;
	pair<int, int> p;
	queue<pair<int, int>> que;
	p.first = 0;
	p.second = 0;

	que.push(p);

	while (que.empty() == false) {
		pair<int, int> val1 = que.front();

		for (int i = 0; i < 4; i++)
		{
			int nextx = val1.first + arr[i][0];
			int nexty = val1.second + arr[i][1];

			if (nextx >= 0 && nextx < N)
				if (nexty >= 0 && nexty < M)
					if (v[nextx][nexty] == 1 && visit[nextx][nexty] == 0)
					{
						v[nextx][nexty] = v[val1.first][val1.second] + 1;
						visit[nextx][nexty] = 1;
						pair<int, int> val2;
						val2.first = nextx;
						val2.second = nexty;
						que.push(val2);
					}
		}
		que.pop();
	}
}

int main() {

	string value;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> value;
		for (int j = 0; j < M; j++)
		{
			if (value[j] == '0') v[i][j] = 0;
			else v[i][j] = 1;
			visit[i][j] = 0;
		}
	}

	bfs();

	cout << v[N - 1][M - 1];
}
