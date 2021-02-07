#include <iostream>
using namespace std;

int map[31][31];
int N, M, H;
bool flag = false;
bool check() {
	for (int i = 1; i <= N; i++) { //세로
		int startx = 1;
		int starty = i; //세로 시작
		while (1) {
			if (startx == H + 1)
				break;
			if (map[startx][starty - 1] == 1)
				starty = starty - 1;
			else if (map[startx][starty] == 1)
				starty = starty + 1;
			startx = startx + 1;
		}
		if (starty != i) {
			return false;
		}
	}
	return true;
}

void chooseLine(int x, int cnt, int total_cnt) {
	if (cnt == total_cnt) {
		if (check() == true)
			flag = true;
	}
	else {
		for (int i = x; i <= H; i++) {
			if (flag == true)
				break;
			for (int j = 0; j < N; j++) {
				if (flag == true)
					break;
				if (map[i][j] == 0) {
					if (map[i][j - 1] == 0 && map[i][j + 1] == 0) {
						map[i][j] = 1;
						chooseLine(i, cnt + 1, total_cnt);
						map[i][j] = 0;
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;
	int answer = 0;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		chooseLine(1, 0, i);
		if (flag == true) {
			answer = i;
			break;
		}
	}
	if (flag == false)
		answer = -1;
	cout << answer << endl;
}