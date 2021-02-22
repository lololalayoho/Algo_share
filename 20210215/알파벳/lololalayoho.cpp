/* https://www.acmicpc.net/problem/1987 */
#include <iostream>
#include <string>
using namespace std;
char map[21][21];
int alpha[26];
int R, C;
int total_cnt;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void check(int row, int col, int cnt) {
	if (total_cnt < cnt)
		total_cnt = cnt;

	for (int i = 0; i < 4; i++) {
		int x = row + dx[i];
		int y = col + dy[i];
		if (x >= 0 && x < R && y >= 0 && y < C) {
			if (alpha[map[x][y] - 'A'] == 0) {
				alpha[map[x][y] - 'A'] = 1;
				check(x, y, cnt + 1);
				alpha[map[x][y] - 'A'] = 0;
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	alpha[map[0][0] - 'A'] = 1;
	check(0, 0, 1);
	cout << total_cnt << endl;
}