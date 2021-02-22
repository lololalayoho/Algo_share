/* https://www.acmicpc.net/problem/1012 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> pq;
int v[51][51];
int visit[51][51];
int M, N, K;
int cnt;
int total = 0;
int arr[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs(int i, int j) {
	pair<int, int> p;
	p.first = i;
	p.second = j;

	visit[i][j] = 1;
	cnt = cnt + 1;

	for (int k = 0; k < 4; k++)
	{
		int nextx = p.first + arr[k][0];
		int nexty = p.second + arr[k][1];

		if (nextx >= 0 && nextx < M) //위치 값이 배열 안에 있으면
			if (nexty >= 0 && nexty < N) //위치 값이 배열 안에 있으면
				if (v[nextx][nexty] == 1 && visit[nextx][nexty] == 0) { //visit check 및 값 존재 check
					dfs(nextx, nexty);
				}
	}
}

int main() {
	int x, y, testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		pq.clear();
		cin >> M >> N >> K;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				v[i][j] = 0;
				visit[i][j] = 0;
			}
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			v[x][y] = 1;
		}

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 0 && v[i][j] == 1) {
					cnt = 0;
					dfs(i, j);
					pq.push_back(cnt);
				}
			}

		cout << pq.size() << endl;

	}
}