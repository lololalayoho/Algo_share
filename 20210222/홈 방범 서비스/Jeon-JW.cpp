//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu&
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, T; // 크기, 비용, 테케
int map[20][20];
int answer;

int mh(int r, int c, int k) {
	int house = 0;

	for (int i = r - k + 1; i <= r + k - 1; i++) {
		for (int j = c - k + 1; j <= c + k - 1; j++) {
			if (i < 0 || j < 0 || i >= N || j >= N) continue;

			int dist = abs(r - i) + abs(c - j);

			if (dist <= k - 1 && map[i][j] == 1)
				house++;
		}
	}

	int cost = house * M - ((k*k) + (k - 1)*(k - 1));

	if (cost >= 0) return house;
	else return -1;
}


void solution(int num) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer = max(answer, mh(i, j, num));
		}
	}
}

int main() {

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			for (int k =0; k < N; k++) {
				cin >> map[j][k];
			}
		}

		answer = 0;
		for (int j = 1; j <= N + 2; j++) {
			solution(j);
		}
		
		cout << "#" << i << " " << answer << endl;
	}


	return 0;
}

/*
10
8 3
0 0 0 0 0 1 0 0
0 1 0 1 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 0
7 7
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 0 0 0
10 5
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 1 0 0 0
0 1 0 0 0 0 0 0 0 1
1 0 0 1 1 1 0 0 0 0
0 1 0 1 0 1 0 0 0 1
0 0 0 0 0 0 1 0 0 1
0 0 1 1 0 0 0 0 0 0
0 0 0 1 0 0 1 1 0 0
15 4
0 0 0 1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 1 0 0 0 1 0 0 0 0 0
1 0 1 1 0 1 0 0 1 0 0 0 0 0 1
0 0 1 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 1 1 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0 1 1 0 1 0
0 0 0 0 0 1 0 1 0 0 1 1 1 1 1
0 0 1 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1 0 0 1 0 1 1 0
0 1 0 0 0 1 0 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 1 0 0 0 0 1 0
1 0 1 0 0 1 0 1 0 0 1 0 0 0 0
0 0 0 0 0 0 1 1 1 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0 0 1 0 0 1 1
0 0 0 0 1 0 0 0 0 0 0 1 0 0 0
15 3
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0 1 1 0 0 0 1
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0 1 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 1 0 0 0 0 0 0
0 1 0 0 0 0 1 0 0 0 1 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 1 0 1 0 0
15 8
0 0 1 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0 0 0 0 0 0 1 1
0 0 0 0 1 0 0 0 1 1 1 0 1 0 0
1 1 0 0 0 1 0 1 0 0 0 0 1 0 0
0 1 0 0 1 0 1 0 1 0 0 0 0 1 1
0 0 0 0 0 0 0 1 0 0 0 1 0 0 0
1 0 0 0 1 0 0 0 1 0 1 0 1 0 1
1 1 1 0 0 0 0 0 1 0 0 0 0 1 0
1 1 0 0 0 0 0 0 1 0 1 0 1 0 0
1 1 0 0 1 0 1 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0 0 1 1 0 1
0 0 0 0 1 0 0 0 1 0 0 0 0 0 0
0 1 0 0 1 1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 1 1 0 0 0 1 1
1 0 0 0 0 1 0 0 0 0 0 1 0 1 1
15 2
1 0 1 1 0 1 1 1 0 1 0 0 0 0 0
1 0 0 1 0 0 0 0 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0 0 0 0 1 0 1 1
1 1 1 1 1 1 1 0 0 1 0 0 1 1 0
0 1 0 1 0 0 0 0 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 1 0 0 0 0 1 1
0 1 1 1 1 1 0 1 0 1 0 0 0 0 1
0 0 1 1 0 0 0 0 0 0 0 0 1 1 1
0 1 1 1 0 0 0 1 1 0 0 1 0 0 1
0 0 1 0 0 1 1 0 1 0 0 0 1 0 0
1 1 1 1 1 0 0 1 1 0 1 1 1 1 1
1 1 0 0 0 0 0 1 0 0 0 0 0 1 0
1 1 0 1 0 0 0 0 0 1 0 0 0 0 1
0 1 0 0 0 0 1 0 0 1 0 1 0 0 0
20 4
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 1 0 0 0
1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1
0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1
0 0 0 0 0 1 1 0 0 1 0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1
0 1 0 0 0 1 0 1 1 1 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
1 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1
0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0 1 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 1 1 0 0
0 0 1 0 1 0 0 0 0 1 1 1 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0
20 10
0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1
0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0
1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 1 1 1 0 0 1 1 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0
1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 1 1 0
0 1 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0 1 1 1 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0
0 0 1 0 1 1 1 1 1 1 0 0 0 1 0 0 0 1 0 1
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0
0 1 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0
20 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/