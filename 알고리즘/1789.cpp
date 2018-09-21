#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.20
1789번 수들의 합

문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최대값은 얼마일까?
입력
첫째 줄에 자연수 S(1≤S≤4,294,967,295)가 주어진다.
출력
첫째 줄에 자연수 N의 최대값을 출력한다.
https://www.acmicpc.net/problem/1789
*/

#include <iostream>

using namespace std;

long long N;

int main() {
	
	scanf("%lld", &N);
	long long count = 0;
	long long sum = 0;
	for (long long i = 1; i <= N; i++) {
		sum += i;
		//printf("%d ", i);
		if (sum > N)
			break;
		else
			count++;
	}
	printf("%lld", count);
	return 0;
}

