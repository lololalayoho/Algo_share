//https://www.acmicpc.net/problem/14501
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n; // 1~15
int t[16];
int p[16];
int check[16];
int date[16]; // 끝나는날
int dp[17];

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		date[i] = i + t[i];
		if (t[i] + i > n+1) check[i] = 1; // 이미 불가능한 경우
	}

	for (int i = 1; i <= n+1; i++) {
		//if (!check[i]) {
		dp[i] = max(dp[i], dp[i - 1]);
			for (int j = 1; j <= n; j++) {
				if (i == date[j]) {
					dp[i] = max(dp[i], dp[j] + p[j]);
				}
			}
		//}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;


	cout << dp[n + 1] << endl;


	return 0;
}