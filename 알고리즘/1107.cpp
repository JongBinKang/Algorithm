#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int v[1000001];
int broken[10] = { 1,1,1,1,1,1,1,1,1,1};

int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a; 
		scanf("%d", &a);
		broken[a] = 0;
	}
	v[100] = 0;
	for (int i = 101; i <= 1000001; i++) {
		v[i] = v[i - 1] + 1;
		int na;
		int mok = i;;
		int j =0;
		while (mok != 0) {
			j++;
			na = mok % 10;
			mok = mok / 10;
			if (broken[na] == 0) {
				j = 210000000;
				break;				
			}
				
		}
		v[i] = min(v[i], j);
	}
	for (int i = 1000000; i >= 0; i--) {
		v[100] = 0;
		if (v[i] != 0 )
			v[i] = min(v[i], v[i + 1] + 1);
		else
			v[i] = v[i+1] + 1;
		int na;
		int mok = i;
		int j = 0;
		while (1) {
			j++;
			na = mok % 10;
			mok = mok / 10;
			if (broken[na] == 0) {
				j = 210000000;
				break;
			}
			if (mok == 0)
				break;
		}
		v[i] = min(v[i], j);
	}
	for (int i =1; i < 100; i++) {
		v[100] = 0;
		v[i] = min(v[i], v[i - 1] + 1);
		int na;
		int mok = i;
		int j = 0;
		while (1) {
			j++;
			na = mok % 10;
			mok = mok / 10;
			if (broken[na] == 0) {
				j = 210000000;
				break;
			}
			if (mok == 0)
				break;
		}
		v[i] = min(v[i], j);
	}
	printf("%d", v[N]);
}