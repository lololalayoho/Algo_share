#include<iostream>

using namespace std;

int N, M; // ����, ���μ��� ����
int H; // �� ���μ����� ���μ��� ���� �� �ִ� ��ġ�� ����
bool map[31][11]; // ���μ� ��ġ
int answer = 4;

// i=i���� Ȯ���ϴ�
bool check() {
	for (int i = 1; i <= N; i++) {
		int row = i, col = 1;
		while (col <= H) { // col�� �� ���μ����� ���μ��� ���� �� �ִ� ����
			if (map[col][row]) { // ���������� ����
				row++;
				col++;
			}
			else if (map[col][row - 1]) { // �������� ����
				row--;
				col++;
			}
			else { // ������ �������
				col++;
			}
		}
		if (row != i) return false;
	}
	return true;
}

void dfs(int count, int col, int row) {
	if (answer <= count) return;
	if (check()) { // ��� ��찡 ���� ���
		answer = count;
		return;
	}

	if (count == 3) return;

	for (int i = col; i <= H; i++) {
		for (int j = row; j < N; j++) {
			// �� ���� ������� ��츸 �߰�.
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