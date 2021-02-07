#include<iostream>
using namespace std;

long long gcd(long a, long b){
	long c;
	while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h) {
	long long answer = 1;
	answer = (long)w * h;
	answer -= (long long)(w + h - gcd(w, h));
	return answer;
}