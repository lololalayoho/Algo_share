#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int *visit;
vector<string> v;
vector<vector<string>> ticket;
vector<vector<string>> answers;
void dfs(string s, int total_size) {
	if (v.size() == total_size + 1)
		answers.push_back(v);
	for (int i = 0; i < ticket.size(); i++) {
		if (ticket[i][0] == s && visit[i] == 0) {
			v.push_back(ticket[i][1]);
			visit[i] = 1;
			dfs(ticket[i][1], total_size);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	ticket = tickets;
	visit = new int[tickets.size() + 1];
	for (int i = 0; i < tickets.size(); i++)
		visit[i] = 0;
	v.push_back("ICN");
	dfs("ICN", tickets.size());
	sort(answers.begin(), answers.end());
	return answers[0];
}