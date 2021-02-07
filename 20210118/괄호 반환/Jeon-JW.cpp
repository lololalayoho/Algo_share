#include<iostream>
#include<string>
using namespace std;

string solution(string p) {
	if (p == "") return "";
	string answer = "";
	string u; // �������� ��ȣ ���ڿ��� �� �̻� �и��� �� ����.
	string v; // v�� �� ���ڿ��� �� �� �ִ�.

	int s1 = 0; int s2 = 0; // (, ) ����
	bool sFlag = 0; // 0�� �� (, 1�� �� )

	if (p[0] == ')') sFlag = 1;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') { s1++; u += "("; }
		else { s2++; u += ")"; }

		if (s1 == s2) {
			for (int j = i + 1; j < p.size(); j++) {
				v += p[j];
			}
			break;
		}
	}

	cout << u << " " << v << endl;

	if (!sFlag) { // �ùٸ� ��ȣ ���ڿ�
		answer += u;
		answer += solution(v);
	}
	else {
		answer += "(";
		answer += solution(v);
		answer += ")";
		if (u.size() != 2) {
			for (int i = 1; i < u.size()-1; i++) {
				if (u[i] == '(') answer += ")";
				else answer += "(";
			}
		}
	}

	return answer;
}

int main() {
	string p;
	cin >> p;

	cout << solution(p) << endl;




	return 0;
}