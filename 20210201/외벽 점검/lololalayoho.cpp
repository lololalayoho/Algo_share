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
//순열을 구해서 구한 순서로 확인하기
void check(int n, int cnt, int total_cnt) {
	if (cnt == total_cnt) {
		for (int i = 0; i < weaks.size(); i++) {
			int start = weaks[i];
			int cnt = 1;
			for (int j = 0; j < index.size(); j++) { //시작지점을 옮기기
				for (int k = 1; k <= index[j]; k++) { //거리마다 위험 구역이 있는지 확인
					if (map[start + k] == 1) //위험 구역이 있으면 cnt + 1
						cnt = cnt + 1;
					if (start + k > n * 2)
						break;
				}
				if (cnt == weaks.size()) { //위험 구역을 check한 갯수가 채워지면 return
					total_flag = true; //더 이상 재귀가 돌지않도록 하기 위한 flag
					return;
				}
				for (int l = 0; l < vertex.size(); l++) { //다음 start가 어디인지 구하는 부분
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