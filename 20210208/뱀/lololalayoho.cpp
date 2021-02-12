#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct snake {
	int x;
	int y;
};
struct order {
	int time;
	char direction;
};
queue<snake> snakes;
vector<order> orders;
int dmove[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[101][101];
int move_snake[101][101];
int total_time = -1;
int snake_dir; // 0 : 북쪽, 1 : 동쪽, 2 : 남쪽, 3 : 서쪽 
int N, K, L;
bool flag = true;

int  change(char spin) {

	if (snake_dir == 0 && spin == 'D')
		return 1;
	if (snake_dir == 1 && spin == 'D')
		return  2;
	if (snake_dir == 2 && spin == 'D')
		return  3;
	if (snake_dir == 3 && spin == 'D')
		return  0;

	if (snake_dir == 0 && spin == 'L')
		return  3;
	if (snake_dir == 1 && spin == 'L')
		return  0;
	if (snake_dir == 2 && spin == 'L')
		return  1;
	if (snake_dir == 3 && spin == 'L')
		return  2;

}

void move() {

	if (total_time == -1) {
		snake s;
		s.x = 0; s.y = 0; snake_dir = 1;
		snakes.push(s);
		move_snake[0][0] = 1;
		total_time = total_time + 1;
	}
	else {
		int nextx = snakes.back().x + dmove[snake_dir][0];
		int nexty = snakes.back().y + dmove[snake_dir][1];
		total_time = total_time + 1;
		if (nextx >= 0 && nexty >= 0 && nextx < N && nexty < N) {
			if (move_snake[nextx][nexty] == 1)// 뱀이 자신과 부딧혔을 때
				flag = false;
			else if (move_snake[nextx][nexty] == 0 && map[nextx][nexty] == 1) { //사과 있을 때
				move_snake[nextx][nexty] = 1;
				map[nextx][nexty] = 0;
				snake s;
				s.x = nextx; s.y = nexty;
				snakes.push(s);
			}
			else { //사과가 없을 때
				move_snake[nextx][nexty] = 1;
				move_snake[snakes.front().x][snakes.front().y] = 0;
				snake s;
				s.x = nextx; s.y = nexty;
				snakes.push(s);
				snakes.pop(); // 가장 오래 된 위치에 있는 뱀의 몸을 없애기
			}
		}
		else
			flag = false;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		order o;
		cin >> o.time >> o.direction;
		orders.push_back(o);
	}
	for (int i = 0; i < orders.size(); i++) {
		while (total_time <= orders[i].time) {
			if (total_time == orders[i].time)
				snake_dir = change(orders[i].direction);
			move();
			if (flag == false)
				break;
		}
		if (flag == false)
			break;
	}
	while (flag == true)
		move();
	cout << total_time << endl;
}