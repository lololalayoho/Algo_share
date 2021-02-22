/* https://www.acmicpc.net/problem/12865 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int DP[102][100002];
struct package {
	int w;
	int v;
};
vector<package> v1;
int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		package p;
		cin >> p.w >> p.v;
		v1.push_back(p);
	}
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j <= K; j++) {
			if (j - v1[i].w >= 0)
				DP[i + 1][j] = max(DP[i][j], v1[i].v + DP[i][j - v1[i].w]);
			else
				DP[i + 1][j] = DP[i][j];
		}
	}
	cout << DP[N][K];
}