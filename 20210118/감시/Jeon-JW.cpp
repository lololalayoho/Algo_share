#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int N, M; // 세로, 가로(row, col)
vector<vector<int>> map(9,vector<int>(9,0));
int cctv[2][100];
int cctvNum;

int func(int n, int state, vector<vector<int>> tempMap) {
	int val = map[cctv[0][n]][cctv[1][n]]; // cctv의 종류
	int stateVal = map[cctv[0][n - 1]][cctv[1][n - 1]]; // 이전 cctv의 종류
	// state에 따른 값 주입. 7은 #과 동일한 효과
	if (n != 0) {
		if (stateVal == 1) {
			if (state == 0) {// 북
				for (int i = cctv[0][n-1]-1; i > 0 ; i--) {
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 1) {// 동
				for (int i = cctv[1][n - 1]+1; i <= M; i++) {
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 2) {// 남
				for (int i = cctv[0][n - 1]+1; i <= N; i++) {
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 3) {// 서
				for (int i = cctv[1][n - 1]-1; i > 0; i--) {
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
		}
		else if (stateVal == 2) {
			if (state == 0) { // 가로
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) {//오른쪽
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 왼쪽
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state = 1) { // 세로
				for (int i = cctv[0][n-1] -1; i >0; i--) { // 위
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) {
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
		}
		else if (stateVal == 3) { // 꺽쇠
			if (state == 0) { // 북 동
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // 북
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // 동
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 1) { // 동 남
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // 동
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // 남
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 2) { // 남 서
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // 남
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 서
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 3) { // 서 북
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 서
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // 북
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
		}
		else if (stateVal == 4) { // 3방향
			if (state == 0) { // 서 북 동
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 서
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // 북
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // 동
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 1) { // 북 동 남
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // 북
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // 동
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // 남
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
			else if (state == 2) { // 동 남 서
				for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // 동
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // 남
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 서
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
			}
			else if (state == 3) { // 남 서 북
				for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // 남
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
				for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 서
					if (tempMap[cctv[0][n - 1]][i] == 6) break;
					if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
				}
				for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // 북
					if (tempMap[i][cctv[1][n - 1]] == 6) break;
					if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
				}
			}
		}
		else if (stateVal == 5) { // 북 동 남 서
			for (int i = cctv[0][n - 1] - 1; i > 0; i--) { // 북
				if (tempMap[i][cctv[1][n - 1]] == 6) break;
				if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
			}
			for (int i = cctv[1][n - 1] + 1; i <= M; i++) { // 동
				if (tempMap[cctv[0][n - 1]][i] == 6) break;
				if (tempMap[cctv[0][n - 1]][i] == 0)tempMap[cctv[0][n - 1]][i] = 7;
			}
			for (int i = cctv[0][n - 1] + 1; i <= N; i++) { // 남
				if (tempMap[i][cctv[1][n - 1]] == 6) break;
				if (tempMap[i][cctv[1][n - 1]] == 0)tempMap[i][cctv[1][n - 1]] = 7;
			}
			for (int i = cctv[1][n - 1] - 1; i > 0; i--) { // 서
				if (tempMap[cctv[0][n - 1]][i] == 6) break;
				if (tempMap[cctv[0][n - 1]][i] == 0) tempMap[cctv[0][n - 1]][i] = 7;
			}
		}
	} // 이전 결과에 따른 북 동 남 서 처리
	if (n == cctvNum) { // 모든 cctv를 설치하였을 경우
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