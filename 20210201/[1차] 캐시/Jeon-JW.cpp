#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cache;
int tempCacheSize = 0; // �� size

int calc(string temp) {
	int answer = 0;
	for (int i = 0; i < cache.size(); i++) {
		if (cache[i] == temp) {	// ã���� ���
			cache.erase(cache.begin() + i);
			cache.push_back(temp);
			return 1;
		}
	}
	if (tempCacheSize == cache.size()) { // cache�� ����� max�� ���
		cache.erase(cache.begin());
		cache.push_back(temp);
		return 5;
	}
	else {
		cache.push_back(temp);
		return 5;
	}
}


int solution(int cacheSize, vector<string> cities) {
	int answer = 0; // ����ð�
	tempCacheSize = cacheSize;
	string str;
	for (int i = 0; i < cities.size(); i++) {
		str = cities[i];
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		answer += calc(str);
	}

	return answer;
}
// ���� �߰��� ������ cache miss��.

int main() {
	vector<string> cities;
	string str;
	for (int i = 0; i < 10; i++) {
		cin >> str;
		cities.push_back(str);
	}

	cout << solution(3, cities) << endl;
	

	return 0;
}
// �� core dump�ɸ����� �𸣰ڳ� ȭ����.