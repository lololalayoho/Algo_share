//https://programmers.co.kr/learn/courses/30/lessons/49994
#include <string>
#include <unordered_map>

using namespace std;

pair<int, int> location;
unordered_map<int, int> map;
int dir[2][4] = {
	{-1,1,0,0}, {0,0,1,-1} // ºÏ³²µ¿¼­
};
int rowVi[11][10];
int colVi[10][11];


int solution(string dirs) {
	int answer = 0;
	int dirLen = dirs.length();
	location = make_pair(5, 5);

	char temp; int dirNum;
	for (int t = 0; t < dirLen; t++) {
		temp = dirs[t];
		if (temp == 'U') {
			dirNum = 0;
		}
		else if (temp == 'D') {
			dirNum = 1;
		}
		else if (temp == 'R') {
			dirNum = 2;
		}
		else if (temp == 'L') {
			dirNum = 3;
		}
		int nr = location.first + dir[0][dirNum];
		int nc = location.second + dir[1][dirNum];

		if (nr < 0 || nr > 10 || nc < 0 || nc > 10) continue;

		if (dirNum == 0) {
			if (!colVi[nr][nc]) answer++;
			colVi[nr][nc] = 1;
		}
		else if (dirNum == 1) {
			if (!colVi[location.first][nc]) answer++;
			colVi[location.first][nc] = 1;
		}
		else if (dirNum == 2) {
			if (!rowVi[nr][location.second]) answer++;
			rowVi[nr][location.second] = 1;
		}
		else if (dirNum == 3) {
			if (!rowVi[nr][nc]) answer++;
			rowVi[nr][nc] = 1;
		}
		location = make_pair(nr, nc);
	}

	return answer;
}