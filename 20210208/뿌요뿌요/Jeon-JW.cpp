//https://www.acmicpc.net/problem/11559
// 틀림 ㅠㅠㅠㅠㅠㅠ
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char map[14][8];
int visited[14][8];
vector<vector<pair<int, int>>> answers;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

void dfs(char cri, int count, vector<pair<int, int>> temp, int row, int col, bool flag) {
	for (int i = 0; i < 4; i++) {
		if (row + dir[0][i] <= 0 && row + dir[0][i] > 12) continue;
		if (col + dir[1][i] <= 0 && col + dir[0][i] > 6) continue;

		if (map[row + dir[0][i]][col + dir[1][i]] == cri && !visited[row + dir[0][i]][col + dir[1][i]]) {
			temp.push_back(make_pair(row + dir[0][i], col + dir[1][i]));
			visited[row + dir[0][i]][col + dir[1][i]] = 1;
			dfs(cri, count + 1, temp, row + dir[0][i], col + dir[1][i], 1);
			temp.pop_back();
			visited[row + dir[0][i]][col + dir[1][i]] = 0;
			flag = 0;
		}
	}

	if (count >= 4 && flag) answers.push_back(temp);
}

void crash() {
	for (int i = 0; i < answers.size(); i++) {
		for (int j = 0; j < answers[i].size(); j++) {
			map[answers[i][j].first][answers[i][j].second] = '.';
		}
	}
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	int rowstate; // 비어있는 가장 위의 부분을 저장하는 값
	for (int i = 1; i <= 6; i++) {
		rowstate = 12;
		for (int j = 12; j > 0; j--) {
			if (map[j][i] == '.') continue;
			map[rowstate][i] = map[j][i];
			map[j][i] = '.';
			rowstate -= 1;
		}
	}
}


int solution() {
	vector<pair<int, int>> temp;
	for (int i = 12; i > 0; i--) {
		for (int j = 6; j > 0; j--) {
			for (int i = 0; i < answers.size(); i++) {
				for (int j = 0; j < answers[i].size(); j++) {
					visited[answers[i][j].first][answers[i][j].second] = 1;
				}
			}
			if (!visited[i][j] && map[i][j] != '.')
				dfs(map[i][j], 0, temp, i, j, 1);
		}
	}
	int size = answers.size();
	for (int i = 0; i < answers.size(); i++) {
		for (int j = 0; j < answers[i].size(); j++) {
			cout << answers[i][j].first << " " << answers[i][j].second << endl;
		}
	}
	cout << size << endl;
	answers.clear();
	if (size != 0) crash();
	else return 0;
	return size;
}

int main() {

	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;
	int preResult = 0;
	for (;;) {
		preResult = solution();
		if (preResult == 0) break;
		result += preResult;

		/*for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}*/
	}

	cout << result << endl;

	return 0;
}