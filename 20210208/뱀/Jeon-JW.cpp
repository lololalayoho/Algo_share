// https://www.acmicpc.net/problem/3190
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n; int k; // 보드의 크기, 사과의 개수
int l; // 뱀의 방향 변환 횟수
int map[102][102];
vector<pair<int, char>> turn;
int snakelen = 1; int snakedir = 2; // 북동서남
vector<pair<int, int>> snakebody;
int sec = 0;

// 문제 - 꼬리가 길어진 상태로 검사해야함
bool solution() {
	bool answer = 1;
	// 머리의 위치
	int row = snakebody[snakebody.size() - 1].first;
	int	col = snakebody[snakebody.size() - 1].second;
	// 움직이기
	snakelen++;
	if (snakedir == 1) {//북
		snakebody.push_back(make_pair(row-1, col));
	}
	else if (snakedir == 2) {//동
		snakebody.push_back(make_pair(row, col+1));
	}
	else if (snakedir == 3) {//남
		snakebody.push_back(make_pair(row + 1, col));
	}
	else if (snakedir == 4) {//서
		snakebody.push_back(make_pair(row, col-1));
	}
	
	// 결과 확인
	// 벽에 박을 경우
	if (snakebody[snakebody.size() - 1].first == 0 || snakebody[snakebody.size() - 1].second == 0 ||
		snakebody[snakebody.size() - 1].first == n + 1 || snakebody[snakebody.size() - 1].second == n + 1) answer = 0;
	// 움직인 결과가 snakebody내에 있을 경우
	for (int i = 0; i < snakebody.size()-1; i++) {
		if (snakebody[snakebody.size() - 1].first == snakebody[i].first
			&& snakebody[snakebody.size() - 1].second == snakebody[i].second) answer = 0;
	}

	// 사과가 없으면
	if (!map[snakebody[snakebody.size() - 1].first][snakebody[snakebody.size() - 1].second]) {
		snakebody.erase(snakebody.begin());
		snakelen--;
	}
	else {
		map[snakebody[snakebody.size() - 1].first][snakebody[snakebody.size() - 1].second] = 0;
	}

	return answer;
}

// 방향 바꾸기
void changedir() {
	if (turn[0].second == 'L') { // 왼쪽 90
		snakedir--;
		if (snakedir < 1) snakedir = 4;
	}
	else { // 오른쪽 90
		snakedir++;
		if (snakedir > 4) snakedir = 1;
	}
	turn.erase(turn.begin()); // 사용하고는 지워주기
}

int main() {
	cin >> n >> k;
	int row, col;
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		map[row][col] = 1;
	}
	cin >> l;
	pair<int, char> temp;
	for (int i = 0; i < l; i++) {
		cin >> temp.first >> temp.second;
		turn.push_back(temp);
	}
	turn.push_back(make_pair(99999999, 'r'));

	snakebody.push_back(make_pair(1, 1)); // 처음에 1,1에서 시작
	// solution의 결과가 0이면 죽은걸로
	bool result;
	for (;;) {
		sec++;
		result = solution();
		if (result == 0) break;
		if (turn[0].first == sec) { // 방향 바꿀 경우
			changedir();
		}
		/*cout << "=========SnakeBody==========" << sec << endl;
		for (int i = 0; i < snakebody.size(); i++) {
			cout << snakebody[i].first << " " << snakebody[i].second << endl;
		}*/
	}

	cout << sec << endl;

	return 0;
}