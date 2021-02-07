#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cache;
int tempCacheSize = 0; // 총 size

int calc(string temp) {
	int answer = 0;
	for (int i = 0; i < cache.size(); i++) {
		if (cache[i] == temp) {	// 찾았을 경우
			cache.erase(cache.begin() + i);
			cache.push_back(temp);
			return 1;
		}
	}
	if (tempCacheSize == cache.size()) { // cache의 사이즈가 max일 경우
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
	int answer = 0; // 실행시간
	tempCacheSize = cacheSize;
	string str;
	for (int i = 0; i < cities.size(); i++) {
		str = cities[i];
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		answer += calc(str);
	}

	return answer;
}
// 새로 추가할 때에도 cache miss임.

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
// 왜 core dump걸리는지 모르겠네 화난다.