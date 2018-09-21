#define _CRT_SECURE_NO_WARNINGS
/*
1476번 날짜계산
https://www.acmicpc.net/problem/1476
2018.04.12
*/

#include <iostream>

using namespace std;

int year[16][29][20];
int main() {
	int ans=0;
	int E=1, S=1, M=1;
	while (1) {
		
		ans += 1;
		year[E][S][M] = ans;
		if (E == 15 && S == 28 && M == 19)
			break;
		if (E == 15)
			E = 1;
		else
			E++;
		if (S == 28)
			S = 1;
		else
			S++;
		if (M == 19)
			M = 1;
		else
			M++;
		
		
	}
	scanf("%d %d %d", &E, &S, &M);
	printf("%d", year[E][S][M]);

}