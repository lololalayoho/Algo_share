#include<iostream>

using namespace std;

int N, M; // 세로, 가로선의 개수
int H; // 각 세로선마다 가로선을 놓을 수 있는 위치의 개수
bool map[31][11]; // 가로선 위치
int answer = 4;

// i=i인지 확인하는
bool check() {
	for (int i = 1; i <= N; i++) {
		int row = i, col = 1;
		while (col <= H) { // col은 각 세로선마다 가로선을 놓을 수 있는 개수
			if (map[col][row]) { // 오른쪽으로 연결
				row++;
				col++;
			}
			else if (map[col][row - 1]) { // 왼쪽으로 연결
				row--;
				col++;
			}
			else { // 연결이 없을경우
				col++;
			}
		}
		if (row != i) return false;
	}
	return true;
}

void dfs(int count, int col, int row) {
	if (answer <= count) return;
	if (check()) { // 모든 경우가 맞을 경우
		answer = count;
		return;
	}

	if (count == 3) return;

	for (int i = col; i <= H; i++) {
		for (int j = row; j < N; j++) {
			// 양 옆이 비어있을 경우만 추가.
			if (!map[i][j] && !map[i][j - 1] && !map[i][j + 1]) {
				map[i][j] = 1;
				dfs(count + 1, i, j + 1);
				map[i][j] = 0;
			}
		}
		row = 1;
	}
}



int main() {
	cin >> N >> M >> H;

	if (M == 0) {
		cout << 0 << endl;
		return 0;
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a;
		cin >> b;
		map[a][b] = 1;
	}

	dfs(0, 1, 1);
	if (answer == 4) cout << "-1" << endl;
	else cout << answer << endl;

	return 0;
}