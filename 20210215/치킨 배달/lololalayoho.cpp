/* https://www.acmicpc.net/problem/15686 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct position {
	int x;
	int y;
	int value;
};

int N, M;
int map[51][51];
vector<position> v;
vector<position> v1;
vector<position> cal;
int answer;
priority_queue<int, vector<int>, greater<int>> pq;
void cal_distance() {
	int sum = 0;
	for (int i = 0; i < v1.size(); i++) {
		int value = 999999999;
		for (int j = 0; j < cal.size(); j++) {
			int happy = abs(v1[i].x - cal[j].x) + abs(v1[i].y - cal[j].y);
			if (happy < value)
				value = happy;
		}
		sum = sum + value;
	}
	answer = sum;
}
void start(int index, int cnt) {
	if (cnt == M) {
		cal_distance();
		pq.push(answer);
		return;
	}
	else {
		for (int k = index; k < v.size(); k++) {
			if (v[k].value == 0) {
				v[k].value = 1;
				position p;
				p.x = v[k].x;
				p.y = v[k].y;
				p.value = v[k].value;
				cal.push_back(p);
				start(k + 1, cnt + 1);
				v[k].value = 0;
				cal.pop_back();
			}
		}
	}
}
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				position p;
				p.x = i; p.y = j; p.value = 0;
				v.push_back(p);
			}
			else if (map[i][j] == 1) {
				position p;
				p.x = i; p.y = j; p.value = 0;
				v1.push_back(p);
			}
		}

	start(0, 0);
	cout << pq.top() << endl;
}