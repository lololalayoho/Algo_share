//https://www.acmicpc.net/problem/9252
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string a, b;
int aLen, bLen;
int dp[1001][1001];
string answer = "";

void solution(int i, int j) {
	if (i == 0 && j == 0) return;
	
	//위, 왼쪽을 확인
	if (dp[i][j] == dp[i - 1][j] && i-1 >=0) solution(i - 1, j); // 위
	else if (dp[i][j] == dp[i][j - 1] && j-1 >=0)solution(i, j - 1); // 왼
	else { // 둘 다 해당이 안되는 경우
		answer = a[i - 1]+ answer;
		//cout << i << j << a[i - 1] << endl;
		solution(i - 1, j - 1);
	}
}


int main() {

	cin >> a;
	cin >> b;
	aLen = a.length(); bLen = b.length();

	//dp만들기
	for (int i = 0; i < aLen; i++) {
		for (int j = 0; j < bLen; j++) {
			if (a[i] == b[j]) { // 문자가 같을경우
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else { // 문자가 다를경우
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}

	//dp검증
	solution(aLen, bLen);
	

	/*for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << answer.length() << endl;
	if (answer.length() != 0) cout << answer << endl;

	return 0;
}