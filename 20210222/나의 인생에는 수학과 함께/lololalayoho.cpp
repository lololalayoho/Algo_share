#include <iostream>
#include <queue>
using namespace std;
int max_array[6][6];
int min_array[6][6];
char map[6][6];
int N;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
struct cal {
	int x;
	int y;
};
void max_bfs() {
	queue<cal> q;
	cal c;
	c.x = 0; c.y = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			max_array[i][j] = -999999999;
	q.push(c);
	max_array[0][0] = map[0][0] - '0';
	while (!q.empty()) {
		for (int i = 0; i < 2; i++) {
			int x = q.front().x + dx[i];
			int y = q.front().y + dy[i];
			if (x >= 0 && x < N && y >= 0 && y < N) {
				if (map[x][y] == '+' || map[x][y] == '-' || map[x][y] == '*') {
					if (max_array[x][y] < max_array[q.front().x][q.front().y]) {
						max_array[x][y] = max_array[q.front().x][q.front().y];
						c.x = x; c.y = y;
						q.push(c);
					}
				}
				else {
					int value;
					if (map[q.front().x][q.front().y] == '+')
						value = max_array[q.front().x][q.front().y] + (map[x][y] - '0');
					else if (map[q.front().x][q.front().y] == '-')
						value = max_array[q.front().x][q.front().y] - (map[x][y] - '0');
					else if (map[q.front().x][q.front().y] == '*')
						value = max_array[q.front().x][q.front().y] * (map[x][y] - '0');
					if (max_array[x][y] < value) {
						max_array[x][y] = value;
						c.x = x; c.y = y;
						q.push(c);
					}
				}
			}
		}
		q.pop();
	}
}

void min_bfs() {
	queue<cal> q;
	cal c;
	c.x = 0; c.y = 0;
	q.push(c);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			min_array[i][j] = 999999999;

	min_array[0][0] = map[0][0] - '0';
	while (!q.empty()) {
		for (int i = 0; i < 2; i++) {
			int x = q.front().x + dx[i];
			int y = q.front().y + dy[i];
			if (x >= 0 && x < N && y >= 0 && y < N) {
				if (map[x][y] == '+' || map[x][y] == '-' || map[x][y] == '*') {
					if (min_array[x][y] > min_array[q.front().x][q.front().y]) {
						min_array[x][y] = min_array[q.front().x][q.front().y];
						c.x = x; c.y = y;
						q.push(c);
					}
				}
				else {
					int value;
					if (map[q.front().x][q.front().y] == '+')
						value = min_array[q.front().x][q.front().y] + (map[x][y] - '0');
					else if (map[q.front().x][q.front().y] == '-')
						value = min_array[q.front().x][q.front().y] - (map[x][y] - '0');
					else if (map[q.front().x][q.front().y] == '*')
						value = min_array[q.front().x][q.front().y] * (map[x][y] - '0');
					if (min_array[x][y] > value) {
						min_array[x][y] = value;
						c.x = x; c.y = y;
						q.push(c);
					}
				}
			}
		}
		q.pop();
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	max_bfs();
	min_bfs();
	cout << max_array[N - 1][N - 1] << " " << min_array[N - 1][N - 1] << endl;
}