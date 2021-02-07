#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// �ܺ��� ���� n, ��� ������ ��ġ�� ��� �迭 weak, �� ģ���� 1�ð� ���� �̵��� �� �ִ� �Ÿ�dist
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = -1; // ��ã���� ��
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