//https://programmers.co.kr/learn/courses/30/lessons/17676
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	vector<pair<int, int>> time;

	for (int i = 0; i < lines.size(); i++)
	{
		string h, m, s, ms;
		int ih, im, is, process;

		lines[i].pop_back();
		h = lines[i].substr(11, 2);
		m = lines[i].substr(14, 2);
		s = lines[i].substr(17, 2);
		ms = lines[i].substr(20, 3);

		ih = stoi(h) * 3600 * 1000;
		im = stoi(m) * 60 * 1000;
		is = stoi(s) * 1000 + stoi(ms);
		process = stof(lines[i].substr(24, 5)) * 1000;

		time.push_back(make_pair(ih + im + is - process + 1, ih + im + is));
	}

	int temp; int count = 1;
	for (int i = 0; i < lines.size(); i++) {
		temp = time[i].second + 1000; // µÞ½Ã°£

		for (int j = i + 1; j < lines.size(); j++) {
			if (temp > time[j].first) count++;
		}

		if (answer < count) answer = count;
		count = 1;
	}



	return answer;
}