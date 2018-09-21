#define _CRT_SECURE_NO_WARNINGS

#define INF 3000*31*12
#include <iostream>
#include <math.h>

using namespace std;

int T;
int cost[4], plan[13], charge[13], ans;


void make_charge(int month, int sum) {
	if (month >= 12) {
		ans = fmin(ans, sum);
		return;
	}

	make_charge(month + 1, sum + cost[0] * plan[month+1]);
	make_charge(month + 1, sum + cost[1]);
	make_charge(month + 3, sum + cost[2]);
	make_charge(month + 12, sum + cost[3]);
}

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		for (int i = 0; i < 4; i++) {
			scanf("%d", &cost[i]);
		}
		for (int i = 1; i < 13; i++) {
			scanf("%d", &plan[i]);
		}
		ans = INF;
		make_charge(0,0);
		printf("#%d %d\n",k,ans);
	}
}