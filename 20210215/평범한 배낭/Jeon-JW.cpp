// https://www.acmicpc.net/problem/12865
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, K;
int weight[101];
int value[101];
int p[101][100001]; // 물건의 개수, 무게

int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> weight[i]; // 무게
		cin >> value[i]; // 가치
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= weight[i]) p[i][j] = max(p[i - 1][j], p[i - 1][j - weight[i]] + value[i]);
			else p[i][j] = p[i - 1][j];
		}
	}

	cout << p[N][K];

	return 0;
}