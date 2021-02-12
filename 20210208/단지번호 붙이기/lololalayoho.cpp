#include <iostream>
#include <string>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int v[26][26];
int visit[26][26];
int N;
int cnt;
int total = 0;
int arr[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs(int i, int j) {
	pair<int, int> p;
	p.first = i;
	p.second = j;
	visit[i][j] = 1;
	cnt = cnt + 1;
	//cout << "count : " << count << endl;

	for (int k = 0; k < 4; k++)
	{
		int nextx = p.first + arr[k][0];
		int nexty = p.second + arr[k][1];

		if (nextx >= 0 && nextx < N) //위치 값이 배열 안에 있으면
			if (nexty >= 0 && nexty < N) //위치 값이 배열 안에 있으면
				if (v[nextx][nexty] == 1 && visit[nextx][nexty] == 0) { //visit check 및 값 존재 check
					dfs(nextx, nexty);
				}
	}
}

int main() {
	string value;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
			if (value[j] == '0') v[i][j] = 0;
			else
				v[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && v[i][j] == 1) {
				cnt = 0;
				total = total + 1;
				dfs(i, j);
				pq.push(cnt);
			}
		}

	cout << pq.size() << endl;

	while (pq.empty() == false) {
		int val = pq.top();
		cout << val << endl;
		pq.pop();
	}
}