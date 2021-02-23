// https://www.acmicpc.net/problem/1012
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

int T, M, N, K;
int X, Y;
bool map[50][50];
bool visit[50][50];
vector<int> answers;
int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};

void bfs(int row, int col) {
	visit[row][col] = 1;
	int nx;
	int ny;
	for (int i = 0; i < 4; i++) {
		nx = row + dir[0][i];
		ny = col + dir[1][i];

		if (nx > 49 || nx < 0) continue;
		if (ny > 49 || ny < 0) continue;
		if (!map[nx][ny] || visit[nx][ny]) continue;
		bfs(nx, ny);
	}
}

int main() {

	cin >> T;

	int answer = 0;

	for (int k = 0; k < T; k++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visit[i][j] && map[i][j]) {
					bfs(i, j);
					answer++;
				}
			}
		}


		answers.push_back(answer);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		answer = 0;
	}


	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << endl;
	}

	return 0;
}