#define _CRT_SECURE_NO_WARNINGS
/*
2193번 이친수
2018.04.12
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
vector <long long int > ans[2];

int main() {
	
	ans[0].push_back(0);
	ans[1].push_back(1);
	ans[0].push_back(1);
	ans[1].push_back(0);

	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		ans[0].push_back(ans[0][i - 1] + ans[1][i - 1]);
		ans[1].push_back(ans[0][i - 1]);
		
	}

	printf("%lld", ans[0][n-1]+ans[1][n-1]);
	return 0;
}