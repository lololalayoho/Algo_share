//https://www.acmicpc.net/problem/17265
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int map[6][6];
int minN = 99999999;
int maxN = -99999999;
/*
	maxN이 0이라는 편견
*/
int dir[2][2] = {
	{1,0}, {0,1}
};

int cal(vector<int> arr) {

	int temp = arr[0] - 48;
	// 5=6 3 = 2 
	int temp2;
	if (n == 5) temp2 = 6;
	else if (n == 3) temp2 = 2;
	for (int i = 0; i <= temp2; i = i + 2) {
		if (arr[i + 1] == 43) {
			temp = temp + (arr[i + 2] - 48);
		}
		else if (arr[i + 1] == 45) {
			temp = temp - (arr[i + 2] - 48);
		}
		else if (arr[i + 1] == 42) {
			temp = temp * (arr[i + 2] - 48);
		}
	}

	return temp;
}


void solution(int i, int j, vector<int> arr) {
	if (i == n && j == n) {
		int temp;
		temp = cal(arr);
		if (temp > maxN) {
			/*for (int i = 0; i < (2 * n - 1); i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
			cout << temp << endl;*/
			maxN = temp;
		}
		if (temp < minN) {
			/*for (int i = 0; i < (2 * n - 1); i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
			cout << temp << endl;*/
			minN = temp;
		}
		return;
	}

	int ni, nj;
	for (int a = 0; a < 2; a++) {
		ni = i + dir[0][a];
		nj = j + dir[1][a];

		if (ni > n || nj > n) continue;
		
		arr.push_back(map[ni][nj]);
		solution(ni, nj, arr);
		arr.pop_back();
	}
}

int main() {

	cin >> n;

	char temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			map[i][j] = (int)temp;
		}
	}

	vector<int> arr;
	arr.push_back(map[1][1]);
	solution(1,1,arr);

	cout << maxN << " " << minN << endl;

	return 0;
}