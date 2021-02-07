#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 외벽의 길이 n, 취약 지점의 위치가 담긴 배열 weak, 각 친구가 1시간 동안 이동할 수 있는 거리dist
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = -1; // 못찾았을 때
	int weakLen = weak.size();
	int distLen = dist.size();

	sort(dist.begin(), dist.end());

	for (int i = 0; i < weakLen; i++) {
		int temp = weak[0] + n;
		for (int j = 1; j < weakLen; j++) {
			weak[j - 1] = weak[j];
		}
		weak[weakLen - 1] = temp;

		do {
			int w = 0;
			int d = 0;

			for (d = 0; d < distLen; d++) {
				int fin = weak[w] + dist[d];
				while (fin >= weak[w]) {
					w++;
					if (w == weak.size()) {
						break;
					}
				}
				if (w == weak.size()) {
					break;
				}
			}

			if (w == weak.size()) {
				if (answer == -1 || d + 1 < answer) {
					answer = d + 1;
				}
			}
		} while (next_permutation(dist.begin(), dist.end()));
	}

	return answer;
}