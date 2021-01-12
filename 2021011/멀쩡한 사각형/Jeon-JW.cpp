#include<iostream>

using namespace std;

long long gcd(long a, long b) // 최대 공약수
{
	long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h) { // 형변환 안하면 안됨.
	long long answer = 1;
	answer = (long)w * h;

	answer -= (long long)(w + h - gcd(w, h));

	return answer;
}

int main() {

	int w = 1;
	int h = 1;
	cin >> w >> h;
	long long answer = solution(w, h);
	cout << answer << endl;

	return 0;
}