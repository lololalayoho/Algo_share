#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int N, M; // ����, ����(row, col)
vector<vector<int>> map(9,vector<int>(9,0));
int cctv[2][100];
int cctvNum;

int func(int n, int state, vector<vector<int>> tempMap) {
	int val = map[cctv[0][n]][cctv[1][n]]; // cctv�� ����
	int stateVal = map[cctv[0][n - 1]][cctv[1][n - 1]]; // ���� cctv�� ����
	// state�� ���� �� ����. 7�� #�� ������ ȿ��
	if (n != 0) {
		if (stateVal == 1) {
			if (state == 0) {// ��
				for (int i = cctv[0][n-1]-1; i > 0 ; i--) {
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 1) {// ��
				for (int i = cctv[1][n - 1]+1; i <= M; i++) {
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 2) {// ��
				for (int i = cctv[0][n - 1]+1; i <= N; i++) {
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 3) {// ��
				for (int i = cctv[1][n - 1]-1; i > 0; i--) {
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
		}
		else if (stateVal == 2) {
			if (state == 0) { // ����
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) {//������
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ����
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state = 1) { // ����
				for (int i = cctv[0][n-1] -1; i >0; i--) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) {
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
		}
		else if (stateVal == 3) { // ����
			if (state == 0) { // �� ��
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 1) { // �� ��
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 2) { // �� ��
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 3) { // �� ��
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
		}
		else if (stateVal == 4) { // 3����
			if (state == 0) { // �� �� ��
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 1) { // �� �� ��
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 2) { // �� �� ��
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 3) { // �� �� ��
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // ��
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
		}
		else if (stateVal == 5) { // �� �� �� ��
			for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // ��
				if (tempMap[i][cctv[1][n - 1]] == 6) break;
				if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
			}
			for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // ��
				if (tempMap[cctv[0][n - 1]][i] == 6) break;
				if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
			}
			for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // ��
				if (tempMap[i][cctv[1][n - 1]] == 6) break;
				if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
			}
			for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // ��
				if (tempMap[cctv[0][n - 1]][i] == 6) break;
				if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
			}
		}
	} // ���� ����� ���� �� �� �� �� ó��
	if (n == cctvNum) { // ��� cctv�� ��ġ�Ͽ��� ���
		int result = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tempMap[i][j] == 0) result++;
			}
		}
		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << tempMap[i][j] << " ";
			}
			cout << endl;
		}*/
		return result;
	}
	
	int answer = 100;
	int val1, val2, val3, val4;
	if (val == 1) {
		val1 = func(n + 1, 0, tempMap);
		val2 = func(n + 1, 1, tempMap);
		val3 = func(n + 1, 2, tempMap);
		val4 = func(n + 1, 3, tempMap);
		answer = min(val1, min(val2, min(val3, val4)));
	}
	else if (val == 2) {
		val1 = func(n + 1, 0, tempMap);
		val2 = func(n + 1, 1, tempMap);
		answer = min(val1, val2);
	}
	else if (val == 3) {
		val1 = func(n + 1, 0, tempMap);
		val2 = func(n + 1, 1, tempMap);
		val3 = func(n + 1, 2, tempMap);
		val4 = func(n + 1, 3, tempMap);
		answer = min(val1, min(val2, min(val3, val4)));
	}
	else if (val == 4) {
		val1 = func(n + 1, 0, tempMap);
		val2 = func(n + 1, 1, tempMap);
		val3 = func(n + 1, 2, tempMap);
		val4 = func(n + 1, 3, tempMap);
		answer = min(val1, min(val2, min(val3, val4)));
	}
	else if (val == 5) {
		answer = func(n + 1, 0, tempMap);
	}
	return answer;
}

int main() {
	vector<vector<int>> tempMap(9,vector<int>(9,0));	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			tempMap[i][j] = map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[0][cctvNum] = i;
				cctv[1][cctvNum] = j;
				cctvNum++;
			}
		}
	}
	
	cout << func(0,0, tempMap) << endl;

	return 0;
}