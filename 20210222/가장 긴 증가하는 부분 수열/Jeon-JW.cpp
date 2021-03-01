//https://www.acmicpc.net/problem/11053
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> dp;


int main() {

	cin >> n;
	
	int temp;
	cin >> temp;
	dp.push_back(temp);

	int answer;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		answer = dp.size();
		for (int j = answer - 1; j >= 0; j--) {
			if (dp[j] < temp) {
				if (j == answer - 1) dp.push_back(temp);
				else dp[j + 1] = temp;
				break;
			}
			if (j == 0) dp[0] = temp;
		}
	}

	cout << dp.size();

	return 0;
}