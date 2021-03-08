#include <iostream>
#include <vector>
using namespace std;
int map[4002][4002];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
struct position {
	int x;
	int y;
	int dir;
	int energy;
};
vector<position> bubble;
position p;
int testcase;
int answer;
int N;
int main() {
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> N;
		answer = 0;
		bubble.clear();
		for (int i = 0; i < N; i++) {
			cin >> p.x >> p.y >> p.dir >> p.energy;
			p.x = (1000 + p.x) * 2;
			p.y = (1000 - p.y) * 2;
			bubble.push_back(p);
		}
		while (bubble.size() > 1) {
			position newbubblebubble[1001];
			int index = 0;
			//이동하기
			for (int i = 0; i < bubble.size(); i++) {
				map[bubble[i].x][bubble[i].y] = 0;
				int nextx = bubble[i].x + dx[bubble[i].dir];
				int nexty = bubble[i].y + dy[bubble[i].dir];
				if (nextx > 0 && nexty > 0 && nextx < 4000 && nexty < 4000) {
					if (map[nextx][nexty] == 0) {
						p.dir = bubble[i].dir; p.x = nextx; p.y = nexty; p.energy = bubble[i].energy;
						newbubblebubble[index] = p;
						index = index + 1;
					}
					map[nextx][nexty] = map[nextx][nexty] + bubble[i].energy;
				}
			}
			bubble.clear();
			for (int i = 0; i < index; i++) {
				if (map[newbubblebubble[i].x][newbubblebubble[i].y] != newbubblebubble[i].energy) {
					answer = answer + map[newbubblebubble[i].x][newbubblebubble[i].y];
					map[newbubblebubble[i].x][newbubblebubble[i].y] = 0;
				}
				else
					bubble.push_back(newbubblebubble[i]);
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
}