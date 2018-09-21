#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.10
2331번 반복 수열
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> d;
int check[10000000] = { 0 };
int main() {
	int a, p, ans, n;

	scanf("%d %d", &a, &p);

	ans = 0;
	n = 1;
	while (1) {
		if (check[a] == false)
			check[a] = n;
		else {
			printf("%d", check[a] - 1);
			break;
		}
		while (a > 0) {
			int tmp = a % 10;
			int tmp2 = 1;
			for (int i = 0; i < p; i++) {
				tmp2 = tmp2 * tmp;
			}
			a = a / 10;
			ans += tmp2;
		}
		a = ans;
		ans = 0;
		n++;
	}

}