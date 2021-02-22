/* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl&categoryId=AV5-BEE6AK0DFAVl&categoryType=CODE&problemTitle=%EC%A0%90%EC%8B%AC&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int map[11][11];
int push_stair[11];
vector<int> visit[2]; //계단에 있는 사람;
priority_queue<int, vector<int>, greater<int>> answer;
struct position {
	int x;
	int y;
	int distance;
	int index;
};
vector<position> stairs;
vector<position> people;
void sorted() {
	for (int i = 0; i < people.size(); i++) {
		int index = i;
		int value = people[i].distance;
		for (int j = i + 1; j < people.size(); j++) {
			if (people[j].index == people[i].index) {
				if (value > people[j].distance) {
					value = people[j].distance;
					index = j;
				}
			}
		}
		swap(people[i], people[index]);
	}
}

void move_stair() {
	int sum = 0;
	for (int s = 0; s < people.size(); s++) {
		people[s].distance = abs(people[s].x - stairs[push_stair[s]].x) + abs(people[s].y - stairs[push_stair[s]].y) + map[stairs[push_stair[s]].x][stairs[push_stair[s]].y] + 1;
		people[s].index = push_stair[s];
	}
	sorted(); //people을 distance를 기준으로 정렬
	while (1) {

		bool flag = true;
		for (int i = 0; i < 2; i++)
			visit[i].clear();
		for (int i = 0; i < people.size(); i++) {
			if (visit[people[i].index].size() < 3 && people[i].distance <= map[stairs[people[i].index].x][stairs[people[i].index].y] && people[i].distance >= 0) {
				if (people[i].distance == 0)
					people[i].distance = -1;
				else {
					visit[people[i].index].push_back(i);
					people[i].distance = people[i].distance - 1;
					flag = false;
				}
			}
			else if (visit[people[i].index].size() == 3 && people[i].distance <= map[stairs[people[i].index].x][stairs[people[i].index].y] && people[i].distance >= 0) {
				flag = false;
				continue;
			}
			else if (people[i].distance > 0) {
				flag = false;
				people[i].distance = people[i].distance - 1;
			}
		}
		if (flag == true)
			break;
		sum = sum + 1;
	}
	answer.push(sum);
}

void check(int start, int cnt, int total_cnt) {
	if (cnt == total_cnt)
		move_stair();
	else {
		for (int i = start; i < people.size(); i++) {
			for (int j = 0; j < stairs.size(); j++) {
				if (push_stair[i] == -1) {
					push_stair[i] = j;
					check(i + 1, cnt + 1, total_cnt);
					push_stair[i] = -1;
				}
			}
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> N;
		//초기화
		for (int i = 0; i < 2; i++)
			visit[i].clear();

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				map[i][j] = 0;
		stairs.clear();
		people.clear();
		while (!answer.empty())
			answer.pop();

		//input
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					position p;
					p.x = i; p.y = j; p.distance = 0; p.index = 0;
					people.push_back(p);
				}
				else if (map[i][j] >= 2) {
					position p;
					p.x = i; p.y = j; p.distance = map[i][j]; p.index = 0;
					stairs.push_back(p);
				}
			}
		}
		for (int i = 0; i < people.size(); i++)
			push_stair[i] = -1;

		check(0, 0, people.size());
		cout << "#" << t << " " << answer.top() << endl;
	}
}