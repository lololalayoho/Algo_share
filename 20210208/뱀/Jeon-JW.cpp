// https://www.acmicpc.net/problem/3190
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n; int k; // ������ ũ��, ����� ����
int l; // ���� ���� ��ȯ Ƚ��
int map[102][102];
vector<pair<int, char>> turn;
int snakelen = 1; int snakedir = 2; // �ϵ�����
vector<pair<int, int>> snakebody;
int sec = 0;

// ���� - ������ ����� ���·� �˻��ؾ���
bool solution() {
	bool answer = 1;
	// �Ӹ��� ��ġ
	int row = snakebody[snakebody.size() - 1].first;
	int	col = snakebody[snakebody.size() - 1].second;
	// �����̱�
	snakelen++;
	if (snakedir == 1) {//��
		snakebody.push_back(make_pair(row-1, col));
	}
	else if (snakedir == 2) {//��
		snakebody.push_back(make_pair(row, col+1));
	}
	else if (snakedir == 3) {//��
		snakebody.push_back(make_pair(row + 1, col));
	}
	else if (snakedir == 4) {//��
		snakebody.push_back(make_pair(row, col-1));
	}
	
	// ��� Ȯ��
	// ���� ���� ���
	if (snakebody[snakebody.size() - 1].first == 0 || snakebody[snakebody.size() - 1].second == 0 ||
		snakebody[snakebody.size() - 1].first == n + 1 || snakebody[snakebody.size() - 1].second == n + 1) answer = 0;
	// ������ ����� snakebody���� ���� ���
	for (int i = 0; i < snakebody.size()-1; i++) {
		if (snakebody[snakebody.size() - 1].first == snakebody[i].first
			&& snakebody[snakebody.size() - 1].second == snakebody[i].second) answer = 0;
	}

	// ����� ������
	if (!map[snakebody[snakebody.size() - 1].first][snakebody[snakebody.size() - 1].second]) {
		snakebody.erase(snakebody.begin());
		snakelen--;
	}
	else {
		map[snakebody[snakebody.size() - 1].first][snakebody[snakebody.size() - 1].second] = 0;
	}

	return answer;
}

// ���� �ٲٱ�
void changedir() {
	if (turn[0].second == 'L') { // ���� 90
		snakedir--;
		if (snakedir < 1) snakedir = 4;
	}
	else { // ������ 90
		snakedir++;
		if (snakedir > 4) snakedir = 1;
	}
	turn.erase(turn.begin()); // ����ϰ�� �����ֱ�
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

	snakebody.push_back(make_pair(1, 1)); // ó���� 1,1���� ����
	// solution�� ����� 0�̸� �����ɷ�
	bool result;
	for (;;) {
		sec++;
		result = solution();
		if (result == 0) break;
		if (turn[0].first == sec) { // ���� �ٲ� ���
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