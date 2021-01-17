#include <iostream>
using namespace std;

int n; // �౸�Ϸ� ���λ�� ¦��
int s[21][21];//�ɷ�ġ
int person[21]; // �� ������
int ans = 1000000000; // ���

void dfs(int index, int count) { // index�� ������ �ô��� count�� 0���ͽ���
	if (count == n / 2) { // ���� ��� �����Ǿ��� ��
		int first = 0, second = 0; // score
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < n+1; j++) {
				if (person[i] && person[j]) first += s[i][j];
				if (!person[i] && !person[j]) second += s[i][j];
			}
		}
		if (ans > abs(first - second)) ans = abs(first - second);
		return;
	}
	for (int i = index; i <= n; i ++ ) {
		if (person[i]) continue; // �̹� ���� �������� ���
		else {
			person[i] = true;
			dfs(i, count + 1);
			person[i] = false;
		}
	}
}


int main() {
	cin >> n; // 4~20

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}

	// ���� ������ ������ �˰��� -> dfs
	dfs(1, 0); // count�� 1���� ����


	cout << ans << endl;

	return 0;
}