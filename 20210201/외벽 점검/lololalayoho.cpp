#include <string>
#include <vector>
#include <iostream>
using namespace std;
int visit[10];
int map[402];
vector<int> index;
vector<int> weaks;
vector<int> dists;
vector<int> vertex;
bool total_flag = false;
//������ ���ؼ� ���� ������ Ȯ���ϱ�
void check(int n, int cnt, int total_cnt) {
	if (cnt == total_cnt) {
		for (int i = 0; i < weaks.size(); i++) {
			int start = weaks[i];
			int cnt = 1;
			for (int j = 0; j < index.size(); j++) { //���������� �ű��
				for (int k = 1; k <= index[j]; k++) { //�Ÿ����� ���� ������ �ִ��� Ȯ��
					if (map[start + k] == 1) //���� ������ ������ cnt + 1
						cnt = cnt + 1;
					if (start + k > n * 2)
						break;
				}
				if (cnt == weaks.size()) { //���� ������ check�� ������ ä������ return
					total_flag = true; //�� �̻� ��Ͱ� �����ʵ��� �ϱ� ���� flag
					return;
				}
				for (int l = 0; l < vertex.size(); l++) { //���� start�� ������� ���ϴ� �κ�
					if (vertex[l] > start + index[j]) {
						start = vertex[l];
						cnt = cnt + 1;
						break;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < dists.size(); i++) {
			if (total_flag == true)
				break;
			if (visit[i] == 0) {
				visit[i] = 1;
				index.push_back(dists[i]);
				check(n, cnt + 1, total_cnt);
				visit[i] = 0;
				index.pop_back();
			}
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	weaks = weak;
	dists = dist;
	for (int i = 0; i < dist.size(); i++)
		visit[i] = 0;
	for (int i = 0; i < weak.size(); i++) {
		map[weak[i]] = 1;
		vertex.push_back(weak[i]);
		map[weak[i] + n] = 1;
		vertex.push_back(weak[i] + n);
	}
	for (int i = 0; i < weak.size(); i++) {

	}
	for (int i = 1; i <= dist.size(); i++) {
		check(n, 0, i);
		if (total_flag == true) {
			answer = i;
			break;
		}
	}
	if (total_flag == false)
		answer = -1;
	return answer;
}