#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int T, ans;
bool magnetic[5][9];
bool check[4];
int dirchange(int dir) {
	return dir == 1 ? -1 : 1;
}
void rotation(int m_num, int dir) {
	if (dir == 1) {
		for (int i = 1; i <= 8; i++) {
			bool tmp = magnetic[m_num][i];
			magnetic[m_num][i] = magnetic[m_num][8];
			magnetic[m_num][8] = tmp;
		}			
	}
	else {
		for (int i = 8; i >= 1; i--) {
			int tmp = magnetic[m_num][i];
			magnetic[m_num][i] = magnetic[m_num][1];
			magnetic[m_num][1] = tmp;
		}
	}
}

void funtion_l(int m_num, int dir) {
	
	if (m_num - 1 > 0 && check[m_num - 1]) {
		rotation(m_num-1, dirchange(dir));
		funtion_l(m_num - 1, dirchange(dir));	
	}
	else
		return;		
}
void funtion_r(int m_num, int dir) {
	rotation(m_num, dir);
	if (m_num + 1 < 5 && check[m_num])
		funtion_r(m_num + 1, dirchange(dir));
	else
		return;
}

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		int spin;
		ans = 0;
		scanf("%d", &spin);
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 8; j++) {
				scanf("%d", &magnetic[i][j]);
			}			
		}
		for (int i = 1; i <= spin; i++) {
			for (int i = 1; i < 4; i++) {
				if (magnetic[i][3] != magnetic[i + 1][7])
					check[i] = true;
			}
			int direc, m_num;
			scanf("%d %d", &m_num, &direc);
			funtion_l(m_num, direc);
			funtion_r(m_num, direc);
			
			memset(check, false, sizeof(check));
		}
		for (int i = 0; i < 4; i++) {
			if (!magnetic[i+1][1])
				continue;
			if (magnetic[i + 1][1])
				ans += pow(2, i);
		}
			//ans += magnetic[i][1];
	
		printf("#%d %d\n",k,ans);
	}
	return 0;
}