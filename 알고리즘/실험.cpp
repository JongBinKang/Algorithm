#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>	
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector <char> str1;
vector <char> str2;

int main() {
	
	char a[100] = { 0, };
	scanf("%s", &a);
	
	for (int i = 0; i < strlen(a); i++) {
		
		str1.push_back(a[i]);
	}

	sort(str1.begin(), str1.end());
	scanf("%s", &a);
	
	for (int i = 0; i < strlen(a); i++) {
		str2.push_back(a[i]);
	}
	sort(str2.begin(), str2.end());
	bool check = false;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i]){
			check = true;
			printf("불일치");
			return 0;
		}
	}
	printf("일치");
}