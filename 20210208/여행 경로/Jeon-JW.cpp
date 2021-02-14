//https://programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
int row;
vector<vector<string>> result;
vector<string> term;

void dfs(string last, vector<vector<string>> tickets) {
	if (term.size() == row + 1) result.push_back(term);
	for (int i = 0; i < row; i++) {
		if (!visited[i] && tickets[i][0] == last) {
			term.push_back(tickets[i][1]);
			visited[i] = 1;
			dfs(tickets[i][1], tickets);
			term.pop_back();
			visited[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	for (int i = 0; i < tickets.size(); i++) {
		visited.push_back(false);
	}
	row = tickets.size(); // 티켓의 개수

	term.push_back("ICN");
	dfs("ICN", tickets);
	sort(result.begin(), result.end());

	return result[0];
}