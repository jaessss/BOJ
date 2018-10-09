//18.10.09 BOJ #No.14501 <퇴사>
//Coments : 점화식 세우는 과정 이해 및 연습 필요
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXN 15+1
using namespace std;
int ans;
int N;
int task[MAXN];
int price[MAXN];
int salary[MAXN];

void DP(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			if (j + task[j] - 1 == i) salary[i] = max((salary[j - 1] + price[j]), (salary[i]));
		}
		salary[i] = max(salary[i], salary[i - 1]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> task[i] >> price[i];
		salary[i] = 0;
	}

	ans = 0;
	DP();
	ans = salary[N];
	cout << ans << endl;

	return 0;
}
