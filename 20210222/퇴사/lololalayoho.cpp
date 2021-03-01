#include <iostream>
#include <algorithm>
using namespace std;
int T[16];
int P[16];
int dp[16];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		dp[i] = P[i];
	}

	for (int i = 1; i <= N; i++) {
		int index = i;
		if (T[i] + i <= N + 1) {
			for (int j = i; j > 0; j--) {
				if (T[j] + j <= i) {
					if (dp[i] < P[j] + P[i]) {
						index = j;
						dp[i] = P[j] + P[i];
					}
				}
			}
			if (index != i)
				P[i] = P[i] + P[index];
		}
		else
			P[i] = 0;
	}
	int max_value = 0;
	for (int i = 1; i <= N; i++) {
		if (max_value < P[i])
			max_value = P[i];
	}
	cout << max_value;
}