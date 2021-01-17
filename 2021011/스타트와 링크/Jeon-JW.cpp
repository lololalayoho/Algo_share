#include <iostream>
using namespace std;

int n; // 축구하러 모인사람 짝수
int s[21][21];//능력치
int person[21]; // 팀 나누기
int ans = 1000000000; // 결과

void dfs(int index, int count) { // index는 어디까지 셌는지 count는 0부터시작
	if (count == n / 2) { // 팀이 모두 결정되었을 때
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
		if (person[i]) continue; // 이미 팀에 속해있을 경우
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

	// 팀을 반으로 나누는 알고리즘 -> dfs
	dfs(1, 0); // count는 1부터 시작


	cout << ans << endl;

	return 0;
}