#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct cir {
	int num;
	int dir;
};
vector<char> v[4]; int k;
vector<cir> condition;
int v_cond[4];
int score;

void cal_score() {
	for (int i = 0; i < 4; i++) {
		if (i == 0 && v[i][0] == '1')
			score = score + 1;
		else if (i == 1 && v[i][0] == '1')
			score = score + 2;
		else if (i == 2 && v[i][0] == '1')
			score = score + 4;
		else if (i == 3 && v[i][0] == '1')
			score = score + 8;
	}
}

void rotate_clock(int index, vector<char> v1) {
	for (int i = 1; i < v1.size(); i++)
		v[index][i] = v1[i - 1];
	v[index][0] = v1[v1.size() - 1];
}
void rotate_unclock(int index, vector<char> v1) {
	for (int i = 0; i < v1.size() - 1; i++)
		v[index][i] = v1[i + 1];
	v[index][v1.size() - 1] = v1[0];
}

void rotation(int num, int dir) {
	//오른쪽 확인 
	v_cond[num - 1] = dir;
	for (int i = num - 1; i < 3; i++) {
		if (v[i][2] != v[i + 1][6]) {
			if (v_cond[i] == 1)
				v_cond[i + 1] = -1;
			else if (v_cond[i] == -1)
				v_cond[i + 1] = 1;
		}
	}
	//왼쪽 확인
	for (int i = num - 1; i >= 1; i--) {
		if (v[i][6] != v[i - 1][2]) {
			if (v_cond[i] == 1)
				v_cond[i - 1] = -1;
			else if (v_cond[i] == -1)
				v_cond[i - 1] = 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		vector<char> v1 = v[i];
		if (v_cond[i] == 1)
			rotate_clock(i, v1);
		else if (v_cond[i] == -1)
			rotate_unclock(i, v1);
	}

}

int main() {
	score = 0;
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			v[i].push_back(s[j]);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cir c;
		cin >> c.num >> c.dir;
		condition.push_back(c);
	}
	for (int i = 0; i < condition.size(); i++) {
		for (int j = 0; j < 4; j++)
			v_cond[j] = 0;
		rotation(condition[i].num, condition[i].dir);
	}
	cal_score();
	cout << score << endl;
}